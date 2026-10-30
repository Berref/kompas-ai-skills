# ksSpcChangeValue - Изменить значение компонента с указанным номером в указанной колонке

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspcchangevaluew.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](kssettuningspcstyleparamw.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspcobjectcreate_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksSpcChangeValue](ksspecification_ksspcchangevalue.html).

Синтаксис:

int ksSpcChangeValue (unsigned int colNumb,

unsigned int itemNumb,

void *val,

unsigned char typeVal);

Входные параметры:

colNumb | \- номер колонки, начиная с единицы,  
---|---  
itemNumb | \- номер компоненты, начиная с единицы,  
val | \- указатель на значение,  
typeVal | \- тип данных.  
  
[Типы данных...](attypes.html)

Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.- в случае неудачи.  
  
Описание:

Функция позволяет изменить значение компонента с номером itemNumb в колонке с номером colNumb.

Если в колонке содержатся данные типа Запись, она может содержать несколько компонентов. При этом itemNumb может быть не равен 1.

Значение параметра typeVal - может лежать в интервале CHAR_ATTR_TYPE ...STRING_ATTR_TYPE (см. ltdefine.h). Если typeVal== STRING_ATTR_TYPE, то val - строка char[MAX_TEXT_LENGTH].

Функция работает в режиме создания нового или редактирования существующего объекта спецификации [ksSpcObjectCreate](ksspcobjectcreate.html); или [ksSpcObjectEdit](ksspcobjectedit.html);

.....

ksSpcChangeValue();

.....

reference spsObj = ksSpcObjectEnd();

Примечание.

При использовании Unicode следует использовать функцию [ksSpcChangeValueW](ksspcchangevaluew.html).

Подразделы:

(отсутствуют)
