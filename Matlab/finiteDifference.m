%Date: 2/19/2110
%Program to test finite difference method
%Input: N for time steps, M for space steps, parameter alpha, and 
%speed of propagation a.
function R = finiteDifference(N,M,alpha,a)

%Set time and space steps
h = 1/N; % time slice
k = 1/M;  % space slices
v = a*h/k;

%Initialize variables
spaceArray = zeros(M+1, 1);

V_exact = zeros(M+1, 1);

%x0 = linspace(0,k,M+1)';
x0 = (0:k:1)'; 
%for j = 1: M,
    %x(j)= (j-1)*k - a;
  %if (0.4 < x(j) < 0.6),
      %u0 = 1;
 %else
     %u0 = 0;
  %end
%end

u0 = sin(2*pi*x0);

%x = (0:k:1)'

u_exact(:,1)= u0;

for j = 1: M,
       %using the step fxn as initial solution
     %if (0.4 < (j-1)*k < 0.6),
         %spaceArray(j,1)= 1;
     %else
         %spaceArray(j,1)= 0;
     %end
   spaceArray(j,1) = sin(2*pi*(j-1)*k);
end

spaceArray(M+1,1) = spaceArray(1,1);

%Propagate over time
x = x0;
for i = 1: N,
    prev1 = spaceArray(M,1);
    cur1 = spaceArray(1,1);
    for j = 1: M,
        nex1 = spaceArray(j+1,1);
        spaceArray(j,1) = cur1 + (1/2)*v*(alpha*(nex1 - 2*cur1 + prev1) - (nex1 - prev1));
        prev1 = cur1;
        cur1 = nex1;
    end
    spaceArray(M+1,1) = spaceArray(1,1);
    
     x = x - v*k;
     
     %for j = 1: M, 
         
         
    % x(j)= (j-1)*k - a*h;
      %exact solution is also a step fxn
    
     %if  (0.4 < x(j)< 0.6)   
          %u_exact(:,i)= 1;
      %else
          %u_exact(:,i)= 0;
      %end
     %end
      
   u_exact(:,i)=sin(2*pi*(x));   
end
    tic
    for j = 1:M, 
        % x(j)= (j-1)*k - a*h ;
         
         %if (0.4 < x(j) < 0.6),
            % V_exact(j,1)= 1;
        %else
            %V_exact(j,1) = 0;
        %end
         
        V_exact(j,1)= sin(2*pi*x(j));
        V_exact(M+1,1) = V_exact(1,1);
       
    end
    toc
     V = V_exact;
     R = spaceArray;
   
     
    
        d = V-R;
        t = d.^2;
         S = sum(t)*k;
         
      E = sqrt(S)
    
    
   
    
   % Error = norm((V-R))
    
%subplot(2,1,1)
plot(R,'--*r');
 xlabel('Time');
 ylabel('U(t,x) ');
 hold on
 plot(u_exact(:,N))
 %plot( u0)
 %plot(V_exact)
 legend('Numerical Solution',' Exact Solution')
 title('FiniteDifference Scheme with a=1,alpha=1, M=10, N=10')
 