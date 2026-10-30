# ksIsModuleSpecificationActive - Проверить, разрешена ли работа со спецификацией

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_kslockfilecache.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksismodule3dactive.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksIsModuleSpecificationActive](ksismodulespecificationactive.html).

Синтаксис Automation:

long ksIsModuleSpecificationActive();

Возвращаемое значение:

1 | \- работа со спецификацией разрешена,  
---|---  
0 | \- работа со спецификацией запрещена.  
  
Примечание:

Если ksIsModuleSpecificationActive == FALSE, работа со спецификацией запрещена.

Для включения работы со спецификацией используйте метод [KompasObject::ksModuleSpecification](kompasobject_ksmodulespecification.html). Этот же метод позволяет отключить работу со спецификацией.

Подразделы:

(отсутствуют)
