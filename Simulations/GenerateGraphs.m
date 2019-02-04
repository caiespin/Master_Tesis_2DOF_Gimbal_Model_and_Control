%--------------------------------------------------------------------------
%Base Perturbance
figure(1)
plot(wBx,'m')
hold on
plot(wBy,'b')
hold on
plot(wBz,'r')
%axis([0,10,-0.015,0.015])
xlabel('Tiempo (seg)') % x-axis label
ylabel('Velocidad Angular (rad/seg)') % y-axis label
legend('wBx','wBy','wBz')
title('Perturbaciones de la Base')
%--------------------------------------------------------------------------
%Chattering Reduction
figure(2)
subplot(2,1,1)
plot(TazSM,'r')
hold on
plot(TelSM,'b')
%axis([0,10,-0.015,0.015])
xlabel('Tiempo (seg)') % x-axis label
ylabel('Par (Nm)') % y-axis label
legend('Taz','Tel')
title('Señal de Control con Efecto Chattering')
subplot(2,1,2)
plot(TazCSM,'r')
hold on
plot(TelCSM,'b')
axis([0,10,-0.015,0.015])
xlabel('Tiempo (seg)') % x-axis label
ylabel('Par (Nm)') % y-axis label
legend('Taz','Tel')
title('Señal de Control con Reduccion de Chattering')
%--------------------------------------------------------------------------
%Accion de control Sliding vs PI
figure(3)
subplot(2,1,1)
plot(wTzCSM,'r')
hold on
plot(wTyCSM,'b')
%axis([0,10,-0.001,0.001])
xlabel('Tiempo (seg)') % x-axis label
ylabel('Velocidad Angular (rad/seg)') % y-axis label
legend('wTz','wTy')
title('Control por Modos Deslizantes')
subplot(2,1,2)
plot(wTzPI,'r')
hold on
plot(wTyPI,'b')
axis([0,10,-0.001,0.001])
xlabel('Tiempo (seg)') % x-axis label
ylabel('Velocidad Angular (rad/seg)') % y-axis label
legend('wTz','wTy')
title('Control Proporcional-Integral')
%--------------------------------------------------------------------------
%Señal de control Sliding vs PI
figure(4)
subplot(2,1,1)
plot(TazCSM,'r')
hold on
plot(TelCSM,'b')
%axis([0,10,-0.015,0.015])
xlabel('Tiempo (seg)') % x-axis label
ylabel('Par (Nm)') % y-axis label
legend('Taz','Tel')
title('Control por Modos Deslizantes')
subplot(2,1,2)
plot(TazPI,'r')
hold on
plot(TelPI,'b')
axis([0,10,-0.015,0.015])
xlabel('Tiempo (seg)') % x-axis label
ylabel('Par (Nm)') % y-axis label
legend('Taz','Tel')
title('Control Proporcional-Integral')
%--------------------------------------------------------------------------
%Effecto de la estabilizacion
figure(5)
subplot(3,1,1)
plot(wBx,'m')
hold on
plot(wBy,'b')
hold on
plot(wBz,'r')
%axis([0,10,-0.015,0.015])
xlabel('Tiempo (seg)') % x-axis label
ylabel('Velocidad Angular (rad/seg)') % y-axis label
legend('wBx','wBy','wBz')
title('Perturbaciones de la Base')
subplot(3,1,2)
plot(wTySw,'b')
hold on
plot(wTzSw,'r')
%axis([0,10,-0.001,0.001])
xlabel('Tiempo (seg)') % x-axis label
ylabel('Velocidad Angular (rad/seg)') % y-axis label
legend('wTy','wTz')
title('Velocidades Angulares')
subplot(3,1,3)
plot(q2Sw,'b')
hold on
plot(q1Sw,'r')
%axis([0,10,-0.001,0.001])
xlabel('Tiempo (seg)') % x-axis label
ylabel('Angles (rad)') % y-axis label
legend('Elevation','Cross-elevation')
title('Angles')


% figure(6)
% subplot(2,1,1)
% plot(q2Sw,'b')
% hold on
% plot(q1Sw,'r')
% %axis([0,10,-0.001,0.001])
% xlabel('Time (sec)') % x-axis label
% ylabel('Angles (rad)') % y-axis label
% legend('Elevation','Cross-elevation')
% title('Angles')
% subplot(2,1,2)
% plot(TazSw,'r')
% hold on
% plot(TelSw,'b')
% %axis([0,10,-0.01,0.01])
% xlabel('Time (sec)') % x-axis label
% ylabel('Torques (Nm)') % y-axis label
% legend('Tel','Taz')
% title('Control Torques')















