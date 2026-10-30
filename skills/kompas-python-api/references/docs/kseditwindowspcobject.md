# ksEditWindowSpcObject - Запустить окно редактирования для объекта спецификации, существующего в графическом документе

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetapplylibraryspcstyle.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksdeletespcdescription.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspcobjectcreate_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksEditWindowSpcObject](ksspecification_kseditwindowspcobject.html).

Синтаксис:

int ksEditWindowSpcObject (reference spcObj);

Входной параметр:

spcObj | \- указатель на объект спецификации.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Функция открывает диалог редактирования для объекта спецификации, расположенного в графическом документе.

2\. Функция запускает процесс. Так как система может работать только с одним процессом, нужно завершить другие процессные функции: [Cursor](cursor.html), [Placement](placement.html), [CommandWindow](commandwindow.html), [ksEditViewObject](kseditviewobject.html), [ksCreateViewObject](kscreateviewobject.html);

Подразделы:

(отсутствуют)
