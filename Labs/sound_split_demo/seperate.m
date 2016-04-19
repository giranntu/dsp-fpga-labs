[x1, Fs1] = audioread('000000110mix2.wav');
[x2, Fs2] = audioread('000000110mix1.wav');
X = [x1, x2]';
Y = sqrtm(inv(cov(X')))*(X-repmat(mean(X,2),1,size(X,2)));
[W,s,v] = svd((repmat(sum(Y.*Y,1),size(Y,1),1).*Y)*Y');

a = W*X; %W is unmixing matrix
subplot(2,2,1); plot(x1); title('mixed audio - mic 1');
subplot(2,2,2); plot(x2); title('mixed audio - mic 2');
subplot(2,2,3); plot(a(1,:), 'g'); title('unmixed wave 1');
subplot(2,2,4); plot(a(2,:),'r'); title('unmixed wave 2');

% audiowrite('unmixed1.wav', a(1,:), Fs1);
% audiowrite('unmixed2.wav', a(2,:), Fs1);