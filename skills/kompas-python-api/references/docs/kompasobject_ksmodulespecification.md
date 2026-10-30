# ksModuleSpecification - Управление возможностью работы со спецификацией

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksmodule3d.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksmaterialdlg.html "К предыдущему разделу")  
---|---  
  
[Интерфейс.](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksModuleSpecification](ksmodulespecification.html).

Синтаксис Automation:

long ksModuleSpecification (BOOL attach);

Входной параметр:

Attach | \- признак выполняемого действия: 1 - включить работу со спецификацией, 0 - выключить работу со спецификацией.  
---|---  
  
Возвращаемое значение:

1 | \- если был инициирован процесс включения или отключения возможности работы со спецификацией,  
---|---  
0 | \- в случае неудачного завершения.  
  
Примечание:

Проверить, включена или отключена возможность работы со спецификацией, можно с помощью метода [KompasObject](kompasobject_ksismodulespecificationactive.html).

Подразделы:

(отсутствуют)
