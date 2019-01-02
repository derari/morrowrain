function Initialize()
	counters = {}
	indices = {}
	local pad = SKIN:GetVariable('spacing')
	left_origin = SKIN:GetVariable('avatarWidth') + 32 + pad
	top_origin = SKIN:GetVariable('topOrigin') + pad
	size = SKIN:GetVariable('iconSize') + pad
	num_rows = SKIN:GetVariable('numRows')
	right_space = SKIN:GetMeter('meterRightSpace')
	min_cols = tonumber(SKIN:GetVariable('minColumns'))
	y_off = 0
end

function ShowGroup(group)
	y_off = SKIN:GetMeasure('calcIconOffset'):GetValue()
	width = -1
	SKIN:Bang('!SetVariable', 'currentGroup', group)
	SKIN:Bang('!UpdateMeterGroup', 'icons')
	SKIN:Bang('!UpdateMeasureGroup', 'Frame')
end

function Arrange(meterName,meterIconName,group)
	local meter = SKIN:GetMeter(meterName)
	local meterIcon = SKIN:GetMeter(meterIconName)
	local index_map = indices[meterName]
	if index_map == nil then
		initIndices(meterName)
		index_map = indices[meterName]
	end
	local index = index_map[group]
	if index == nil then
		meter:Hide()
		meterIcon:Hide()
		return
	end
	local x = math.floor(index / num_rows)
	local y = index % num_rows
	meter:SetX(left_origin + size*x)
	meter:SetY(top_origin + size*y + y_off)
	meterIcon:SetX(left_origin + size*x + 8)
	meterIcon:SetY(top_origin + size*y + 8)
	meter:Show()
	meterIcon:Show()
	if x > width then
		width = x < (min_cols-1) and (min_cols-1) or x
		SKIN:Bang('!SetVariable', 'FrameWidth', left_origin+width*size+size+2+16)
		SKIN:Bang('!UpdateMeasureGroup', 'Frame')
	end
end

function initIndices(meterName)
	local index_map = {}
	indices[meterName] = index_map
	local meter = SKIN:GetMeter(meterName)
	local groups = meter:GetOption('Group')
	for group in string.gmatch(groups, "([^|]+)") do
		group_index = counters[group] or 0
		index_map[group] = group_index
		counters[group] = group_index + 1
	end
end
