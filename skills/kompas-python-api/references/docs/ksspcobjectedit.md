# ksSpcObjectEdit - Редактировать объект спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspcobjectend.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksspcobjectcreatew.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspcobjectcreate_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksSpcObjectEdit](ksspecification_ksspcobjectedit.html).

Синтаксис:

int ksSpcObjectEdit (reference spcObj);

Входной параметр:

spcObj | \- указатель на объект спецификации.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. После вызова данного метода у объекта можно изменить атрибуты, геометрию, линии выноски, позицию, массу.

2\. Редактирование объекта завершится вызовом функции [ksSpcObjectEnd](ksspcobjectend.html).

Подразделы:

(отсутствуют)
