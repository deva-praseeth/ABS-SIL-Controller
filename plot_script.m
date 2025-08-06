sim("Plant_Model.slx")
time=ans.pedal.time;
p=ans.pedal.signals.values;
vR=ans.velocity.signals(1).values;
vF=ans.velocity.signals(2).values;

axis_p=subplot(1,2,1);
plot(time,p,'Color',[0 0.5 0],LineWidth=1.5)
title('Driver Input')
grid("on")
xlabel("t(s)")

axis_v=subplot(1,2,2);hold on
plot(time,vR,'b',LineWidth=1.5)
plot(time,vF,'r',LineWidth=1.5)
title('Velocity')
grid("on")
xlabel("t(s)")
ylabel('v(Km/h)')

print('ABS_plot.pdf','-dpdf','-bestfit')