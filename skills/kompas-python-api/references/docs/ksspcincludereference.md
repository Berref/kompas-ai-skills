# ksSpcIncludeReference - Добавить или изменить геометрию или линии-выноски в объекте спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspcmassa.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksspcdoclinksclearex.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspcobjectcreate_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksSpcIncludeReference](ksspecification_ksspcincludereference.html).

Синтаксис:

int ksSpcIncludeReference (reference obj, unsigned char clear);

Входные параметры:

obj | \- группа объектов или объект вида,  
---|---  
clear | \- признак обработки существующей геометрии объекта спецификации: 0 - добавить новые объекты к существующей геометрии, 1 - удалить геометрию, 2 - очистить список линий выносок.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

Если obj == 0 и clear == 0, очищается список объектов и список линий выносок.

Подразделы:

(отсутствуют)
