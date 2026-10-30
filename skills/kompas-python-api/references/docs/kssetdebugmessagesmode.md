# ksSetDebugMessagesMode - Включить/выключить режим автоматического вывода сообщений о результатах работы библиотеки

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](ksslidebackground.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](ksinitfilepreviewfuncw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksSetDebugMessagesMode](kompasobject_kssetdebugmessagesmode.html)

Синтаксис:

int LIB_FUNC ksSetDebugMessagesMode( int debugMode );

Входной параметр:

debugMode | \- флаг состояния режима (1 - включить, 0 - выключить).  
---|---  
  
Возвращаемое значение:

| \- предыдущее состояние флага режима.  
---|---  
  
Примечание

1\. При включенном режиме сообщения выдаются сразу после возникновении ошибки.

2\. Данной функцией рекомендуется пользоваться только в режиме отладки библиотеки.

3\. Дополнительно о работе с ошибками библиотеки см. [ReturnResult](returnresult.html) (для Automation - [KompasObject::ksReturnResult](kompasobject_ksreturnresult.html)).

4\. После показа сообщения, если ошибка не является фатальной, флаг ошибки сбрасывается.

Подразделы:

(отсутствуют)
