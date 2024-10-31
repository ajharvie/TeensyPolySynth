for i = 1:50
    for j = 1:257
        waveform(j,i) = ((50-i)*saw(j) + i*square(j))/50;
    end
end
for i = 51:100
    for j = 1:257
        k = i - 50;
        waveform(j,i) = ((50-k)*square(j) + k*triangle(j))/50;
    end
end
waveform = transpose(round(waveform));
