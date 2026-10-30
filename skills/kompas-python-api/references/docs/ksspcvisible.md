# ksSpcVisible - Установить признак видимости компонента

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspecificationonsheet.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksspcposition.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspcobjectcreate_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksSpcVisible](ksspecification_ksspcvisible.html).

Синтаксис:

int ksSpcVisible (unsigned int colNumb,

unsigned int itemNumb,

unsigned char flagOn);

Входные параметры:

colNumb | \- номер колонки, начиная с единицы,  
---|---  
itemNumb | \- номер компоненты, начиная с единицы,  
flagOn | \- признак видимости компонента: 1 -включить, 0- выключить.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Функция работает в режиме создания нового или редактирования существующего объекта спецификации.

2\. В случае записи в колонке может быть несколько компонент и itemNumb может быть не равен 1.

Подразделы:

(отсутствуют)
