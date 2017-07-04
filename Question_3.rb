def concat(array_of_arrays)
	concatenated = array_of_arrays.flatten
	return concatenated
end

array_of_arrays = [1, 2, 3, [4, 5, [6, 7, [8, 9], 10]]]
print concat(array_of_arrays)