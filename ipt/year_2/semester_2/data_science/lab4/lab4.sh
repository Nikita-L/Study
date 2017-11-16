d_name=LC81760262014170LGN00
d2_name=LC81820252014180LGN00
extractFile () # Розархивирование всех файлов в архиве и одного файла
{
  if [[ $2 == 'all' ]]; then
    for file in `tar -tf $1.tar.gz`
    do
      if [[ `echo $file | cut -d'.' -f 2` == 'TIF' ]]; then
        f=`echo $file | cut -d'_' -f 2 | cut -d'.' -f 1`
        dir="$1/$f"
        mkdir $dir
        tar -xzf $d_name.tar.gz -C $dir $file
        mv "$dir/$file" "$dir/$f.tif"
      fi
    done
  else
    mkdir $1
    mkdir $1/B$2
    tar -xzf $1.tar.gz -C $1/B$2 $1_B$2.TIF
    mv "$1/B$2/$1_B$2.TIF" "$1/B$2/B$2.tif"
  fi
}

cd data/raw
mkdir $d_name
extractFile $d_name "all" # Розархивирование всех файлов

cd $d_name
gdal_merge.py -o ../../clean/task2.tif -separate B5/B5.tif B6/B6.tif B2/B2.tif # Конкатинация каналов видимого, ближнего и среднего инфракрасного диапазона

cd ../../clean
gdalwarp -tr 100 100 -t_srs '+proj=utm +zone=36' task2.tif task3.tif # Перепроектирование изображения в другую кординатною систему

cd ../raw
extractFile $d2_name "2" # Розархивирование только файла с индентивикатором B2
gdalwarp $d_name/B3/B3.tif $d2_name/B2/B2.tif ../clean/task4.tif # Конкатинация изображений разного размера

# Задание 5 выполнено в qgis, обрезка из файла data/raw/LC81760262014170LGN00/B3/B3.tiff