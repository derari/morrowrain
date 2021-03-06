[Variables]
@Include=#@#Includes\weather_today_yahoo.inc

[MeasureDayname1]
Measure=Time
Format=%A
UpdateDivider=-1
Substitute="Sunday":"Mon","Monday":"Tue","Tuesday":"Wed","Wednesday":"Thu","Thursday":"Fri","Friday":"Sat","Saturday":"Sun"

[MeasureDayname2]
Measure=Time
Format=%A
UpdateDivider=-1
Substitute="Sunday":"Tue","Monday":"Wed","Tuesday":"Thu","Wednesday":"Fri","Thursday":"Sat","Friday":"Sun","Saturday":"Mon"

[MeasureDayname3]
Measure=Time
Format=%A
UpdateDivider=-1
Substitute="Sunday":"Wed","Monday":"Thu","Tuesday":"Fri","Wednesday":"Sat","Thursday":"Sun","Friday":"Mon","Saturday":"Tue"

[MeasureWeatherKey0]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=9
DynamicVariables=1
Group=ForcastMeasure
Substitute=#KeySubstitute#

[MeasureRain0]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=10
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempDay0Web]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=11
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempDay0]
Measure=Calc
Formula=((#Unit# = 1)? [MeasureTempDay0Web] : Round(([MeasureTempDay0Web]-32)*5/9))
DynamicVariables=1
UpdateDivider=1
Group=NeedRefresh

[MeasureTempNight0Web]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=12
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempNight0]
Measure=Calc
Formula=((#Unit# = 1)? [MeasureTempNight0Web] : Round(([MeasureTempNight0Web]-32)*5/9))
DynamicVariables=1
UpdateDivider=1
Group=NeedRefresh

[MeasureWeatherKey1]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=13
DynamicVariables=1
Group=ForcastMeasure
Substitute=#KeySubstitute#

[MeasureRain1]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=14
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempDay1Web]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=15
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempDay1]
Measure=Calc
Formula=((#Unit# = 1)? [MeasureTempDay1Web] : Round(([MeasureTempDay1Web]-32)*5/9))
DynamicVariables=1
UpdateDivider=1
Group=NeedRefresh

[MeasureTempNight1Web]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=16
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempNight1]
Measure=Calc
Formula=((#Unit# = 1)? [MeasureTempNight1Web] : Round(([MeasureTempNight1Web]-32)*5/9))
DynamicVariables=1
UpdateDivider=1
Group=NeedRefresh

[MeasureWeatherKey2]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=17
DynamicVariables=1
Group=ForcastMeasure
Substitute=#KeySubstitute#

[MeasureRain2]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=18
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempDay2Web]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=19
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempDay2]
Measure=Calc
Formula=((#Unit# = 1)? [MeasureTempDay2Web] : Round(([MeasureTempDay2Web]-32)*5/9))
DynamicVariables=1
UpdateDivider=1
Group=NeedRefresh

[MeasureTempNight2Web]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=20
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempNight2]
Measure=Calc
Formula=((#Unit# = 1)? [MeasureTempNight2Web] : Round(([MeasureTempNight2Web]-32)*5/9))
DynamicVariables=1
UpdateDivider=1
Group=NeedRefresh

[MeasureWeatherKey3]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=21
DynamicVariables=1
Group=ForcastMeasure
Substitute=#KeySubstitute#

[MeasureRain3]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=22
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempDay3Web]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=23
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempDay3]
Measure=Calc
Formula=((#Unit# = 1)? [MeasureTempDay3Web] : Round(([MeasureTempDay3Web]-32)*5/9))
DynamicVariables=1
UpdateDivider=1
Group=NeedRefresh

[MeasureTempNight3Web]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=24
DynamicVariables=1
Group=ForcastMeasure

[MeasureTempNight3]
Measure=Calc
Formula=((#Unit# = 1)? [MeasureTempNight3Web] : Round(([MeasureTempNight3Web]-32)*5/9))
DynamicVariables=1
UpdateDivider=1
Group=NeedRefresh