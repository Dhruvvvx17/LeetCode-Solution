matrix1 = [1 2; 3 4]

matrix2 = [5 5; 6 6]

matrix1 * matrix2

matrix1 + matrix2

-----------------------------

[m,n] = size(x1)

out = zeros(m,n)

for i = 1:m
    for j = 1:n
        out(i,j) = x1(i,j) + x2(i,j)
        j = j+1
    end
    i = i+1
end

disp(out)

-------------------------------