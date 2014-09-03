clear

d =(0:.1:10)';
t = d -.1;
for i = 1:length(t),
    if (t(i)<.4:.6),
        y = 1;
    else
        y = 0;
    end
       
end
plot(y, '-or')
    

