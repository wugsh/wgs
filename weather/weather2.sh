#!/bin/bash
set -e
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


        #echo "Program starting..."

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

       
        #######################################################################

        #以下的功能寻找天气质量

        #Getting the weather quality from http://www.pm25.com//XX.html



            #echo " Getting the file from http://www.pm25.com//xx.html"


            air_url="www.pm25.com/"$city_PY.html


            wget -O - $air_url > city.air



            city_air=$(sed -n '/全部监测点/p' city.air | awk -F '"' '{print $12}')



            echo "The city air is " $city_air > city-weather



            city_pm25=$(sed -n '/全部监测点/p' city.air | awk -F '"' '{print $10}')


            echo "The city pm 2.5 figure is: " $city_pm25 >> city-weather


            city_aqi=$(sed -n '/全部监测点/p' city.air | awk -F '"' '{print $8}')


            echo "The city's air AQI index is:" $city_aqi >> city-weather

#################################################################
		#以下是获取城市天气的部分

   		 weather_state=$(sed -n '/bi_info_weather/p' city.air | awk -F '"' '{print $6}')
		 
		 
		 echo "The city weather state is:" $weather_state >> city-weather


	     temperature=$(sed -n '/bi_info_weather/p' city.air | awk -F '</' '{print $2}')
	    
		
		 echo "The city temperature is:" $temperature >> city-weather
    }

#####################测试函数###################################

GetWeatherAir 甘肃 gansu 兰州 lanzhou 
#GetWeatherAir 山东 shandong 济宁 jining
rm city.*
mail -s "weather" 18794202957@139.com < city-weather 
