function Initialize()
	measureDisks = SKIN:GetMeasure('measureDisks')
	meterItemFrames = {}
	meterItemIcons = {}
	meterItemLabels = {}
	meterChargeFrames = {}
	meterChargeBars = {}
	for i = 1, 100 do
		mIF = SKIN:GetMeter('meterItemFrame_' .. i)
		if not mIF then break end
		mII = SKIN:GetMeter('meterItemIcon_' .. i)
		mIL = SKIN:GetMeter('meterItemLabel_' .. i)
		mCF = SKIN:GetMeter('meterChargeFrame_' .. i)
		mCB = SKIN:GetMeter('meterChargeBar_' .. i)
		if not mII then
			print('Missing meterItemIcon_' .. i)
			break
		end
		if not mIL then
			print('Missing meterItemLabel_' .. i)
			break
		end
		if not mCF then
			print('Missing meterChargeFrame_' .. i)
			break
		end
		if not mCB then
			print('Missing meterChargeBar_' .. i)
			break
		end
		meterItemFrames[i] = mIF
		meterItemIcons[i] = mII
		meterItemLabels[i] = mIL
		meterChargeFrames[i] = mCF
		meterChargeBars[i] = mCB
	end
	offset = 2 * meterChargeFrames[1]:GetY() / 32
	width = meterChargeFrames[1]:GetY() + SKIN:GetVariable('Spacing', 0)
	padLeft = SKIN:GetVariable('PadLeft') - width
end

function Update()
	local i = 1
	local result = measureDisks:GetStringValue()
	for drive_data in string.gmatch(result, 'Caption.-Size=%d*') do
		ShowDrive(i, drive_data)
		i = i + 1
	end
	for i = i, table.getn(meterItemFrames) do
		HideItem(i)
	end
	SKIN:Bang('!UpdateMeterGroup mUpdate')
	SKIN:Bang('!Redraw')
end

function ShowDrive(i, data)
	local cap, t, free, size = string.match(data, 'Caption=([A-Z]*:).-DriveType=(%d).-FreeSpace=(%d*).-Size=(%d*)')
	local mIF = meterItemFrames[i]
	local mII = meterItemIcons[i]
	local mIL = meterItemLabels[i]
	local mCF = meterChargeFrames[i]
	local mCB = meterChargeBars[i]
	local hasData = free ~= '' and size ~= ''
	local imageName
	SKIN:Bang('!SetOption meterItemLabel_' .. i .. ' Text "' .. cap .. '\\"')
	if t == '3' then
		imageName = 'book_' .. (i % 4)
	elseif t == '2' then
		imageName = 'note_' .. (i % 3)
	else
		if hasData then
			imageName = 'scroll_' .. (i % 2)
		else
			imageName = 'scroll_closed_' .. (i % 2)
		end
	end
	SKIN:Bang('!SetOption meterItemIcon_' .. i .. ' ImageName "#@#Images\\' .. imageName .. '.png"')
	mIF:SetX(padLeft + i*width)
	mII:SetX(padLeft + i*width + offset)
	mIL:SetX(padLeft + i*width + offset)
	mCF:SetX(padLeft + i*width)
	mCB:SetX(padLeft + i*width + offset)
	mIF:Show()
	mII:Show()
	mIL:Show()
	if hasData then
		free = tonumber(free)
		size = tonumber(size)
	end
	if hasData and free < size then
		mCF:Show()
		mCB:Show()
		mCB:SetW(mCF:GetW() * 8 * free / size / 9)
	else
		mCF:Hide()
		mCB:Hide()	
	end
end

function HideItem(i)
	meterItemFrames[i]:Hide()
	meterItemIcons[i]:Hide()
	meterItemLabels[i]:Hide()
	meterChargeFrames[i]:Hide()
	meterChargeBars[i]:Hide()
end

-- Unknown (0)
-- No Root Directory (1)
-- Removable Disk (2)
-- Local Disk (3)
-- Network Drive (4)
-- Compact Disc (5)
-- RAM Disk (6)