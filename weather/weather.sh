#!/bin/bash

#时间：2015-6-21
#版本1.1，时间2015-7-6，更改脚本为函数调用式
#author: Lion Lan

##########################################################
#GetWeatherAir函数说明：
#功能，传入省市的信息，得到该城市的天气和空气参数
#1、参数说明
#   需要传递四个变量 省中文名称 省拼音 市中文名称 市拼音
#   调用示例 GetWeatherAir 河北 hebei 唐山 tangshan
#2、函数使用
#   默认函数中使用echo测试打印了取得的值（见注释部分2），实际使用中可以注释掉echo语句直接重定向输出使用
##########################################################

function GetWeatherAir()
    {
        #This module using to get the weather of one province, such as from webpage:http://www.weather.com.cn/html/province/henan.shtml


        echo "Program starting..."

        #############################################################

        #以下是变量定义，定义省（拼音和中文），市（拼音和中文）

        province=$1

        province_PY=$2

        city=$3

        city_PY=$4


        ###########################注释部分2##################################

        #以下是传出的变量，可以直接使用

        #weather_state 

        #天气质量


        #temperature1

        #最高天气温度


        #temperature2

        #最低天气温度


        #city_air

        #天气质量


        #city_pm25

        #pm2.5指数


        #city_aqi

        #aqi指数

        #############################################################


            #Module 1, Wget the webpage from internet and saved as weather in current directory.


            echo "Getting the weather from webpage..."



            #The url where get the weather page. This page is from China Meteorologic Administration, Henan.


            url="http://www.weather.com.cn/html/province/"$province_PY".shtml"



            #date_doay is today's date, such as 2015-06-27


            date_today=$(date +'%Y-%m-%d')



            logFile=$date_today.log



            wget -O - $url > weather_province  




            echo "Got the weather file from internet."



            #Module 2, Analysize the weather file and getting the information


            echo "Getting the weather information..."




            #Geting the line where include the weather


            sed -n '/'${city}'天气预报/p' weather_province > province.weather


            echo " Province weather file created."




            #As all the information at one line, replace <dl> as \n, making a city at a line


            sed -n '/<dl>/p' province.weather | sed 's/<dl>/\n/g' > city.weather


            echo " Citys weather file created."




            #Geting the city weather as format lines


            sed -n '/'${city}'/p' city.weather | sed 's/</\n</g' > one_city.weather


            echo " city Weather file created."




                #Analysize from the file to get the state information and temputer


                echo "     Anaysizing the weather state"


                weather_state=$(sed -n '/img alt/p' one_city.weather | awk -F '"' '{print $2}' | sed -n '1p')


                echo "The weather state is " $weather_state




                #Getting the tempture


                sed -n '/℃/p' one_city.weather | awk -F '>' '{print $2}'




                temperature1=$(sed -n '/℃/p' one_city.weather | awk -F '>' '{print $2}' | sed -n '1p')


                temperature2=$(sed -n '/℃/p' one_city.weather | awk -F '>' '{print $2}' | sed -n '2p')





                echo "The high temperature is " $temperature1


                echo "The low temperature is " $temperature2


        #######################################################################

        #以下的功能寻找天气质量

        #Getting the weather quality from http://www.pm25.com//XX.html



            echo " Getting the file from http://www.pm25.com//xx.html"


            air_url="www.pm25.com/"$city_PY.html


            wget -O - $air_url > city.air



            city_air=$(sed -n '/全部监测点/p' city.air | awk -F '"' '{print $12}')



            echo "The city air is " $city_air



            city_pm25=$(sed -n '/全部监测点/p' city.air | awk -F '"' '{print $10}')


            echo "The city pm 2.5 figure is: " $city_pm25


            city_aqi=$(sed -n '/全部监测点/p' city.air | awk -F '"' '{print $8}')


            echo "The city's air AQI index is:" $city_aqi

    }

#####################测试函数###################################

#GetWeatherAir 河南 henan 周口 zhoukou
GetWeatherAir 山东 shandong 济宁 jining
#rm city.* *.weather weather_province
