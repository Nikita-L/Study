# install.packages("foreach", repos="http://R-Forge.R-project.org")
# install.packages("doMC", repos="http://R-Forge.R-project.org")
library(foreach) # Используются итераторы, поскольку они быстрее встроенных циклов
library(doMC)
registerDoMC(cores=4)
setwd("/home/nikita/Notebooks/SRP/lab1_R")
source("additional.R")

foreach(i = 1:27) %do% { # Загрузка данных
  region.name <- regionName(i)
  index <- sprintf( "%02d", i)
  link.ind <- paste(index, ".txt", sep = "")
  link <- paste("http://www.star.nesdis.noaa.gov/smcd/emb/vci/gvix/G04/ts_L1/ByProvince/Mean/L1_Mean_UKR.R", link.ind, sep = "")
  download.file(link, destfile=paste("data/raw/", index, " ", region.name, " ", format(Sys.time(), "%Y-%m-%d %H:%M:%S"), ".csv", sep = ""), method="internal")
}
raw.path <- "data/raw/"
raw.data <- list.files(path = raw.path)
lapply(raw.data, function(x) { # Очистка данных
  table <- read.csv(paste(raw.path, x, sep = ""), skip = 1)
  table <- table[!(table$SMN < 0 | table$SMT < 0 | table$VCI < 0 | table$TCI < 0 | table$VHI < 0 | table$X.Area_VHI_LESS_15 < 0 | table$X.Area_VHI_LESS_35 < 0),]
  names(table)[1] <- "Год"
  names(table)[2] <- "Неделя"
  names(table)[8] <- "Процент площади где VHI < 15%"
  names(table)[9] <- "Процент площади где VHI < 35%"
  write.csv(table, paste("data/clean/", x, sep = ""), row.names = F)
})
j <- 0
for (i in region_names){ # Изменение индексов
  j <- j + 1
  current_file <- paste0("data/clean/", list.files(path = "data/clean/", pattern = glob2rx(paste0("?? ", i, " ????-??-?? ??:??:??.csv"))))
  new_current_file <- paste0("data/clean/", sprintf( "%02d", j), substring(current_file, 14))
  file.rename(current_file, new_current_file)
}
df <- plotMake("Киев", "VHI")
extCount(df)
area(df, 70, VHI.35 = T)