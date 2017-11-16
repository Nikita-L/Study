main_path=$HOME
check=0

clear
echo $USER
echo $main_path
read pause
some_files="$(find $main_path/ -name '*.jpg' -user $USER)"
clear

saveFile () # Зберегти файл в архів
{
    if tar -tf $main_path/back_up_.tar | grep $2; then # Якщо такий файл вже існує в архіві
        for (( i = 0; i < 6; )); do
            clear
            echo "Do you want to archive '$1' again [Yes/No/YesAll/NoAll/Exit]:"
            read answer
            clear
            if [ "$answer" = "Yes" ]; then # Так, перезаписати
                tar --delete -f $main_path/back_up_.tar $2
                tar -uf $main_path/back_up_.tar $1
                break;
            elif [ "$answer" = "No" ]; then # Ні, не перезаписувати
                break;
            elif [ "$answer" = "NoAll" ]; then # Ні для всіх
                return 3
            elif [ "$answer" = "YesAll" ]; then # Так для всіх
                tar --delete -f $main_path/back_up_.tar $2
                tar -uf $main_path/back_up_.tar $1
                return 1
            elif [ "$answer" = "Exit" ]; then # Вийти
                return 2
            else
                errors=5
                let "errors -= $i"
                ((i++))
                if [ "$errors" != 0 ]; then
                    clear
                    echo "You have $errors tries left, be patient!"
                    read pause
                fi
            fi
        done
    else
        tar -uf $main_path/back_up_.tar $1
    fi
    return 0
}

for f in $some_files; do
    file=$(echo $f | cut -c 2-)
    if [[ "$check" -eq 1 ]]; then # Так для всіх
        tar --delete -f $main_path/back_up_.tar $file
        tar -uf $main_path/back_up_.tar $f
    elif [[ "$check" -eq 2 ]]; then # Вийти
        break;
    elif [[ "$check" -eq 3 ]]; then # Ні для всіх
        :
    elif [ -n "$(find $main_path/ -name 'back_up_*_????-??-??_??:??:??.tar')" ]; then # Якщо архів вже існує, перезаписати його
        mv $main_path/back_up_*_????-??-??_??:??:??.tar $main_path/back_up_.tar
        saveFile $f $file
        check=$?
    elif [ -f "$main_path/back_up_.tar" ]; then # Зберегти файл
        saveFile $f $file
        check=$?
    else
        tar -cf $main_path/back_up_.tar $f
    fi
done

mv $main_path/back_up_.tar $main_path/back_up_`echo $USER`_$(date '+%Y-%m-%d_%H:%M:%S').tar # Додати в назву ім’я користувача, дату та час
chmod 444 $main_path/back_up_*_????-??-??_??:??:??.tar # Зміна прав на отриманий архів
ls -lh $main_path
chmod 744 $main_path/back_up_*_????-??-??_??:??:??.tar
read pause

check=0
extractFile () # Розархівувати файл
{
    for (( i = 0; i < 6; )); do
        clear
        echo "Do you want to replace '$1' [Yes/No/YesAll/NoAll/Exit]:"
        read answer
        clear
        if [ "$answer" = "Yes" ]; then # Так, перезаписати
            rm $1
            tar -xf $main_path/back_up_*_????-??-??_??:??:??.tar -C / $2
            break;
        elif [ "$answer" = "No" ]; then # Ні, не перезаписувати
            break;
        elif [ "$answer" = "NoAll" ]; then
            return 3
        elif [ "$answer" = "YesAll" ]; then # Так для всіх
            rm $1
            tar -xf $main_path/back_up_*_????-??-??_??:??:??.tar -C / $2
            return 1
        elif [ "$answer" = "Exit" ]; then # Вийти
            return 2
        else
            errors=5
            let "errors -= $i"
            ((i++))
            if [ "$errors" != 0 ]; then
                clear
                echo "You have $errors tries left, be patient!"
                read pause
            fi
        fi
    done
    return 0
}

for f in $some_files; do
    file=$(echo $f | cut -c 2-)
    if [[ "$check" -eq 1 ]]; then # Так для всіх
        rm $f
        tar -xf $main_path/back_up_*_????-??-??_??:??:??.tar -C / $file
    elif [[ "$check" -eq 2 ]]; then # Вийти
        break;
    elif [ ! -f $f ]; then # Якщо файла немає, то розархівувати
        tar -xf $main_path/back_up_*_????-??-??_??:??:??.tar -C / $file
    elif [[ "$check" -ne 3 ]]; then # Розархівувати. Якщо файли відрізняються, то зробити запит
        change_date=$(stat -c %y $f | head -c -17)
        change_date=${change_date// /_}
        archive_name=$(echo $main_path/back_up_*_????-??-??_??:??:??.tar)
        archive_date=${archive_name: -23:19}
        year_c=$(echo $change_date | cut -d"-" -f1)
        year_a=$(echo $archive_date | cut -d"-" -f1)
        year_c=$(echo $year_c | sed 's/^0*//')
        year_a=$(echo $year_a | sed 's/^0*//')
        diff=$(($year_c-$year_a))
        if [[ "$diff" -gt 0 ]]; then
            extractFile $f $file
            check=$?
        elif [[ "$diff" -lt 0 ]]; then
            :
        else
            month_c=$(echo $change_date | cut -d"-" -f2)
            month_a=$(echo $archive_date | cut -d"-" -f2)
            month_c=$(echo $month_c | sed 's/^0*//')
            month_a=$(echo $month_a | sed 's/^0*//')
            diff=$(($month_c-$month_a))
            if [[ "$diff" -gt 0 ]]; then
                extractFile $f $file
                check=$?
            elif [[ "$diff" -lt 0 ]]; then
                :
            else
                day_c=$(echo $change_date | cut -d"-" -f3 | head -c -10)
                day_a=$(echo $archive_date | cut -d"-" -f3 | head -c -10)
                day_c=$(echo $day_c | sed 's/^0*//')
                day_a=$(echo $day_a | sed 's/^0*//')
                diff=$(($day_c-$day_a))
                if [[ "$diff" -gt 0 ]]; then
                    extractFile $f $file
                    check=$?
                elif [[ "$diff" -lt 0 ]]; then
                    :
                else
                    hour_c=$(echo $change_date | cut -d"_" -f2 | head -c -7)
                    hour_a=$(echo $archive_date | cut -d"_" -f2 | head -c -7)
                    hour_c=$(echo $hour_c | sed 's/^0*//')
                    hour_a=$(echo $hour_a | sed 's/^0*//')
                    diff=$(($hour_c-$hour_a))
                    if [[ "$diff" -gt 0 ]]; then
                        extractFile $f $file
                        check=$?
                    elif [[ "$diff" -lt 0 ]]; then
                        :
                    else
                        min_c=$(echo $change_date | cut -d":" -f2 )
                        min_a=$(echo $archive_date | cut -d":" -f2 )
                        min_c=$(echo $min_c | sed 's/^0*//')
                        min_a=$(echo $min_a | sed 's/^0*//')
                        diff=$(($min_c-$min_a))
                        if [[ "$diff" -gt 0 ]]; then
                            extractFile $f $file
                            check=$?
                        elif [[ "$diff" -lt 0 ]]; then
                            :
                        else
                            sec_c=$(echo $change_date | cut -d":" -f3 )
                            sec_a=$(echo $archive_date | cut -d":" -f3 )
                            sec_c=$(echo $sec_c | sed 's/^0*//')
                            sec_a=$(echo $sec_a | sed 's/^0*//')
                            diff=$(($sec_c-$sec_a))
                            if [[ "$diff" -ge 0 ]]; then
                                extractFile $f $file
                                check=$?
                            else
                                :
                            fi
                        fi
                    fi
                fi
            fi
        fi
    else # Ні для всіх
        :
    fi
done