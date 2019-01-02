function Gradient(value, gradient)
	-- print(value)
	data = split(gradient)
	for i = 1, table.getn(data), 5 do
		local key = data[i]
		if value < key then
			if i == 1 then
				return result(data[i+1],data[i+2],data[i+3],data[i+4])
			else
				local r,g,b,a = mix(data, i, value)
				return result(r,g,b,a)
			end
		end
	end
	local i = table.getn(data)
	return result(data[i-3],data[i-2],data[i-1],data[i])
end

function split(gradient)
	local data = {}
	local i = 1
	for s in string.gmatch(gradient, '[-]?%d+') do
		data[i] = tonumber(s)
		i = i + 1
	end
	return data
end

function mix(gradient, i, value)
	local key1 = gradient[i]
	local key2 = gradient[i-5]
	local ratio = (value - key1)/(key2 - key1)
	-- print('mix ' .. i .. ' ' .. ratio)
	-- print(key1 ..','.. key2)
	-- print(gradient[i+1] ..','.. gradient[i+2] ..','.. gradient[i+3])
	-- print(gradient[i-4] ..','.. gradient[i-3] ..','.. gradient[i-2])
	
	local l1,a1,b1 = rgb2lab(gradient[i+1],gradient[i+2],gradient[i+3])
	local l2,a2,b2 = rgb2lab(gradient[i-4],gradient[i-3],gradient[i-2])
	-- print('lab1 ' .. l1 .. ',' .. a1 .. ',' .. b1)
	-- print('lab2 ' .. l2 .. ',' .. a2 .. ',' .. b2)
	
	local l3 = l1 + ratio*(l2-l1)
	local a3 = a1 + ratio*(a2-a1)
	local b3 = b1 + ratio*(b2-b1)
	-- print('lab3 ' .. l3 .. ',' .. a3 .. ',' .. b3)
	
	local r,g,b = lab2rgb(l3,a3,b3)
	local alpha = gradient[i+4]*(1-ratio) + gradient[i-1]*ratio
	return r,g,b, alpha
end

function rgb2lab(r,g,b)
	local x,y,z
	r = r / 255
	g = g / 255
	b = b / 255

	r = (r > 0.04045) and math.pow((r + 0.055) / 1.055, 2.4) or r / 12.92
	g = (g > 0.04045) and math.pow((g + 0.055) / 1.055, 2.4) or g / 12.92
	b = (b > 0.04045) and math.pow((b + 0.055) / 1.055, 2.4) or b / 12.92

	x = (r * 0.4124 + g * 0.3576 + b * 0.1805) / 0.95047
	y = (r * 0.2126 + g * 0.7152 + b * 0.0722) / 1.00000
	z = (r * 0.0193 + g * 0.1192 + b * 0.9505) / 1.08883

	x = (x > 0.008856) and math.pow(x, 1/3) or (7.787 * x) + 16/116
	y = (y > 0.008856) and math.pow(y, 1/3) or (7.787 * y) + 16/116
	z = (z > 0.008856) and math.pow(z, 1/3) or (7.787 * z) + 16/116

	return (116 * y) - 16, 500 * (x - y), 200 * (y - z)
end

function lab2rgb(l,a,b)
	local x,y,z,R,G,B
	y = (l + 16) / 116
	x = a / 500 + y
	z = y - b / 200

	x = 0.95047 * ((x * x * x > 0.008856) and x * x * x or (x - 16/116) / 7.787);
	y = 1.00000 * ((y * y * y > 0.008856) and y * y * y or (y - 16/116) / 7.787);
	z = 1.08883 * ((z * z * z > 0.008856) and z * z * z or (z - 16/116) / 7.787);

	R = x *  3.2406 + y * -1.5372 + z * -0.4986;
	G = x * -0.9689 + y *  1.8758 + z *  0.0415;
	B = x *  0.0557 + y * -0.2040 + z *  1.0570;

	R = (R > 0.0031308) and (1.055 * math.pow(R, 1/2.4) - 0.055) or 12.92 * R;
	G = (G > 0.0031308) and (1.055 * math.pow(G, 1/2.4) - 0.055) or 12.92 * G;
	B = (B > 0.0031308) and (1.055 * math.pow(B, 1/2.4) - 0.055) or 12.92 * B;

	return math.max(0, math.min(1, R)) * 255, math.max(0, math.min(1, G)) * 255, math.max(0, math.min(1, B)) * 255
end


function result(r,g,b,a)
	return r .. ',' .. g .. ',' .. b .. ',' .. a
end