# ksReturnResult - Получить результат работы библиотеки

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Методы вывода на экран ](ag91931.html) |  Scroll [ [ [ ](kompasobject_ksslidebackground.html "К следующему разделу")](ag91931.html "На уровень выше")](kompasobject_ksmessageboxresult.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ReturnResult](returnresult.html).

Синтаксис Automation:

long ksReturnResult();

Возвращаемое значение:

| \- Код ошибки в зависимости от типа документа: [графического](errorcodes.html) или [документа-модели](errortype3d.html) при выполнении библиотечной программы.  
---|---  
  
Примечание:

1\. Коды ошибок документа-модели и графического документа частично совпадают, поэтому их нужно обрабатывать в зависимости от выполняемых операций.

2\. Ошибка с номером >0 не является фатальной. Отрицательный номер ошибки приводит к завершению программы.

3\. Текст ошибок можно получить методом [KompasObject::ksStrResult](kompasobject_ksstrresult.html).

4\. Сообщение с текстом ошибки можно получить, используя метод [KompasObject_ksMessageBoxResult](kompasobject_ksmessageboxresult.html).

5\. Сбросить ошибку, если она не фатальная, можно, используя метод [KompasObject_ksResultNULL](kompasobject_ksresultnull.html).

Подразделы:

(отсутствуют)
