# EnableTaskAccess, PumpWaitingMessages - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void EnableTaskAccess_Example (void)

{

EnableTaskAccess(0); //запретили доступ к задаче

for(int i=0; i<10000; i)

{

LineSeg(10, 10i, 20, 10i, 1);

if(!(i%100))

{

//посылаем необрабатываемое сообщение своему приложению

//для выполнения процесса в фоновом режиме

::PostAppMessage(::GetCurrentTask(), 0, 0, 0);

// через каждые 100 отрезков обрабатываем очередь сообщений

// при этом Windows получает возможность выполнить свои

// действия (например переключиться на другую задачу)

PumpWaitingMessages();

}

}

EnableTaskAccess(1); //разрешили доступ к задаче

}; /* EnableTaskAccess_Example */
