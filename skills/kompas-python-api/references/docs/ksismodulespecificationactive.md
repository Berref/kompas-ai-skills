# ksIsModuleSpecificationActive - Проверить, разрешена ли работа со спецификацией

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksisslavespcopened.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetwidthcolumnspc.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksIsModuleSpecificationActive](kompasobject_ksismodulespecificationactive.html)

Синтаксис:

int ksIsModuleSpecificationActive();

Возвращаемое значение:

1 | \- работа со спецификацией разрешена,  
---|---  
0 | \- работа со спецификацией запрещена.  
  
Примечание:

Если ksIsModuleSpecificationActive == FALSE, работа со спецификацией запрещена.

Для включения работы со спецификацией используйте функцию [ksModuleSpecification](ksmodulespecification.html). Эта же функция позволяет отключить работу со спецификацией.

Подразделы:

(отсутствуют)
