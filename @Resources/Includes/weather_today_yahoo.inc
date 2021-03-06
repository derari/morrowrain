
[Variables]

WeatherURL=https://www.yahoo.com/news/weather
;Your location is automatically located. If it's incorrect or you want a custom place, access to https://www.yahoo.com/news/weather
;Click "Change Location", type in then choose where you want. After that, copy new webpage link and replace it with this measure URL. And refresh skin!


Forcast=data-reactid="197".*<img.*60x60\/(.*)@2x.png.*<span.*-->(\d*)<.*<span class="high.*-->(\d*)<.*span class="low.*-->(\d*)<.*<img.*60x60\/(.*)@2x.png.*<span.*-->(\d*)<.*<span class="high.*-->(\d*)<.*span class="low.*-->(\d*)<.*<img.*60x60\/(.*)@2x.png.*<span.*-->(\d*)<.*<span class="high.*-->(\d*)<.*span class="low.*-->(\d*)<.*<img.*60x60\/(.*)@2x.png.*<span.*-->(\d*)<.*<span class="high.*-->(\d*)<.*span class="low.*-->(\d*)<

KeySubstitute="rain_day_night":"Rainy","scattered_showers_day_night":"Rainy","windy_day_night":"Windy","mostly_cloudy_day_night":"Mostly Cloudy","cloudy_day_night":"Cloudy","partly_cloudy_day":"Partly Cloudy","partly_cloudy_night":"Partly Cloudy","snow_rain_mix_day_night":"Rain And Snow","fair_day":"Mostly Clear","fair_night":"Mostly Clear","clear_day":"Clear","clear_night":"Clear","flurries_day_night":"Snow","snow_day_night":"Snow","thundershowers_day_night":"Thunder Showers"
Group=NeedRefresh

;.*<span class="high D\(ib\) Miw\(32px\).*-->(.*)<.*<span class="high D\(ib\) Miw\(32px\).*-->

;Forcast=<span class="high D\(ib\) Miw\(32px\).*-->(.*)<.*<span class="high D\(ib\) Miw\(32px\).*-->(.*)<.*<span class="high D\(ib\) Miw\(32px\).*-->

;(.*)<.*<span class="high D\(ib\) Miw\(32px\).*-->(.*)<.*<span class="high D\(ib\) Miw\(32px\).*-->(.*)<.*<span class="high D\(ib\) Miw\(32px\).*-->(.*)<.*<span class="high D\(ib\) Miw\(32px\).*-->(.*)<

[UnitCode]
Measure=Calc
Formula=#Unit#
Substitute="1":"°F","0":"°C"
DynamicVariables=1
UpdateDivider=1
Group=NeedRefresh

[AutoRefreshAfterAnHour]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 2000 | PauseEverything | Wait 3600000 | RefreshSkin
PauseEverything=[!PauseMeasureGroup ForcastMeasure][!PauseMeasureGroup NeedRefresh]
RefreshSkin=[!Refresh]

[RefreshWeatherMeters]
Measure=Plugin
Plugin=ActionTimer
ActionList1=UpdateMeasures | Wait 10 | UpdateMeters
UpdateMeasures=[!UpdateMeasureGroup NeedRefresh]
UpdateMeters=[!UpdateMeterGroup Weather][!Redraw]

[Weather]
Measure=Plugin
Plugin=Webparser
URL=#WeatherURL#
RegExp=(?siU)<h1 class="city.*data-reactid="7">(.*)</h1>.*<div class="My\(2px\).*60x60\/(.*)@2x.png.*data-reactid="26">(.*)<.*<span class="Va\(m\) Px\(6px\)" data-reactid="29"><\!-- react-text: 30 -->(.*)<.*data-reactid="33"><\!-- react-text: 34 -->(.*)<.*<span class="Va\(t\)" data-reactid="37">(.*)</span>.*<a class="C\(#fff\) Va\(m\)" href="(.*)" data.*<span class="D\(ib\) W\(1\/1\).*data-reactid="19">(.*)<.*#Forcast#.*Feels like.*data-reactid="477">(.*)°</div>
StringIndex=7
DynamicVariables=1
UpdateDivider=-1
FinishAction=[!CommandMeasure AutoRefreshAfterAnHour "Execute 1"][!CommandMeasure RefreshWeatherMeters "Execute 1"]

[CurrentLocationTime]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=8
DynamicVariables=1
UpdateDivider=1
Substitute="11 PM":"23","11 AM":"11","12 AM":"24","1 AM":"1","2 AM":"2","3 AM":"3","4 AM":"4","5 AM":"5","6 AM":"6","7 AM":"7","8 AM":"8","9 AM":"9","10 AM":"10","12 PM":"12","1 PM":"13","2 PM":"14","3 PM":"15","4 PM":"16","5 PM":"17","6 PM":"18","7 PM":"19","8 PM":"20","9 PM":"21","10 PM":"22"
Group=NeedRefresh

;-------------------------------------------
;--------------MAIN INFO--------------------
;-------------------------------------------
[MeasureLocation]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=1
DynamicVariables=1
Substitute="":"Unknown location, configure manually"
Group=NeedRefresh

[MeasureTempDayWeb]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=4
DynamicVariables=1
Group=NeedRefresh

[MeasureTempDay]
Measure=Calc
Formula=((#Unit# = 1)? [MeasureTempDayWeb] : Round(([MeasureTempDayWeb]-32)*5/9))
DynamicVariables=1
UpdateDivider=1
Group=NeedRefresh

[MeasureTempNightWeb]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=5
DynamicVariables=1
Group=NeedRefresh

[MeasureTempNight]
Measure=Calc
Formula=((#Unit# = 1)? [MeasureTempNightWeb] : Round(([MeasureTempNightWeb]-32)*5/9))
DynamicVariables=1
UpdateDivider=1
Group=NeedRefresh

[MeasureTempWeb]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=6
DynamicVariables=1
Group=NeedRefresh

[MeasureTemp]
Measure=Calc
Formula=((#Unit# = 1)? [MeasureTempWeb] : Round(([MeasureTempWeb]-32)*5/9))
DynamicVariables=1
Group=NeedRefresh

[MeasureTempCelsius]
Measure=Calc
Formula=Round(([MeasureTempWeb]-32)*5/9)
DynamicVariables=1
Group=NeedRefresh

[MeasureWeatherKey]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=2
DynamicVariables=1
Substitute=#KeySubstitute#

[MeasureWeatherDescription]
Measure=Plugin
Plugin=Webparser
URL=[Weather]
StringIndex=3
DynamicVariables=1
Group=NeedRefresh