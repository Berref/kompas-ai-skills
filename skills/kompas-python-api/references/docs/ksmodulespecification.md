# ksModuleSpecification - Управление возможностью работы со спецификацией

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](kssetapplylibraryspcstyle.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksisslavespcopened.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksModuleSpecification](kompasobject_ksmodulespecification.html).

Синтаксис:

int ksModuleSpecification (unsigned char attach);

Входной параметр:

attach | признак выполняемого действия: 1 - включить работу со спецификацией, 0 - выключить работу со спецификацией.  
---|---  
  
Возвращаемое значение:

1 | \- если был инициирован процесс включения или отключения возможности работы со спецификацией,  
---|---  
0 | \- в случае неудачного завершения.  
  
Примечание:

Проверить, включена или отключена работа со спецификацией, можно с помощью функции [ksIsModuleSpecificationActive](ksismodulespecificationactive.html).

5\. При использовании ANSI следует использовать функцию [ksSpcObjectCreate](ksspcobjectcreate.html).

Подразделы:

(отсутствуют)
