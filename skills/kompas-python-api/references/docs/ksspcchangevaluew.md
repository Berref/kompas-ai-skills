# ksSpcChangeValueW - Изменить значение компоненты с указанным номером в указанной колонке (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspccount.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksspcchangevalue.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksSpcChangeValue](ksspecification_ksspcchangevalue.html).

Синтаксис:

int ksSpcChangeValueW (unsigned int colNumb,

unsigned int itemNumb,

void* val,

unsigned char typeVal);

Входные параметры:

colNumb | \- номер колонки, начиная с единицы,  
---|---  
itemNumb | \- номер компоненты, начиная с 1,  
val | \- указатель на значение,  
typeVal | \- тип данных.  
  
[Типы данных...](attypes.html)

Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Описание:

Функция позволяет изменить значение компоненты с номером itemNumb в колонке с номером colNumb.

Если в колонке содержатся данные типа Запись, она может содержать несколько компонент. При этом itemNumb может быть не равен 1.

Значение параметра typeVal - может лежать в интервале CHAR_ATTR_TYPE ...STRING_ATTR_TYPE (см. ltdefine.h). Если typeVal== STRING_ATTR_TYPE, то val - строка wchar_t[MAX_TEXT_LENGTH].

Функция работает в режиме создания нового или редактирования существующего объекта спецификации [ksSpcObjectCreate](ksspcobjectcreate.html); или [ksSpcObjectEdit](ksspcobjectedit.html);

.....

ksSpcChangeValueW();

.....

reference spsObj = ksSpcObjectEnd();

Примечание.

При использовании ANSI следует использовать функцию [ksSpcChangeValue](ksspcchangevalue.html).

Подразделы:

(отсутствуют)
