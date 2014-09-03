clear
clc
M=100
DelX=1/M
a=0.5;
for j=1:1:M
     if (j-1)*DelX<0.4
     vn(j)=0;
     elseif (j-1)*DelX>0.6
     vn(j)=0;    
     else
     vn(j)=1;
     end
end

for j=1:1:M
    if a <=(j-1)*DelX
        if ((j-1)*DelX-a)<0.4
        uN(j)=0;
        elseif ((j-1)*DelX-a)>0.6
        uN(j)=0;    
        else
        uN(j)=1;
        end
    else
        if (1-a+(j-1)*DelX)<0.4
        uN(j)=0;
        elseif (1-a+(j-1)*DelX)>0.6
        uN(j)=0;    
        else
        uN(j)=1;
        end
    end
    
        end
     
plot(vn)
hold on
plot(uN,'r')