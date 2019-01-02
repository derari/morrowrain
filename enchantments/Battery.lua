
function Initialize()
	measureBatteryPercent = SKIN:GetMeasure('measureBatteryPercent')
	measureBatteryStatus = SKIN:GetMeasure('measureBatteryStatus')
	measureACLine = SKIN:GetMeasure('measureACLine')
	meterBatteryBG = SKIN:GetMeter('batteryBG')
	meterBatteryCharge = SKIN:GetMeter('batteryCharge')
	colorLow = SKIN:GetVariable('colorDestruction')
	colorMed = SKIN:GetVariable('colorConjuration')
	colorHigh = SKIN:GetVariable('colorIllusion')
	colorCharge = colorHigh
	colorFull = SKIN:GetVariable('colorRestoration')
	colorOther = SKIN:GetVariable('colorMysticism')
end

function Update()
	local status = measureBatteryStatus:GetValue()
	if status == 0 then
		SKIN:Bang('!SetOption', 'batteryBG', 'ImageTint', colorOther)
		meterBatteryCharge:Hide()
		return 'missing'
	end
	local ac = measureACLine:GetValue()
	local percent = measureBatteryPercent:GetValue()
	local result = 'low'
	local color
	-- local color = colorLow
	if percent > 67 then
		result = 'high'
		-- color = colorHigh
	elseif percent > 33 then
		result = 'med'
		-- color = colorMed
	end
	if ac == 0 then
		meterBatteryCharge:Hide()
		color = '[&scriptGradient:Gradient('.. percent .. ", '25: " .. colorLow .. " | 50: " .. colorMed .. " | 100: " .. colorHigh .. "')]"
	else
		meterBatteryCharge:Show()
		color = percent > 95 and colorFull or colorCharge
	end
	SKIN:Bang('!SetOption', 'batteryBG', 'ImageTint', color)
	return result
end