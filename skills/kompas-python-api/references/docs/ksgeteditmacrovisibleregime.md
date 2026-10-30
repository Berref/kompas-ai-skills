# ksGetEditMacroVisibleRegime - Находится ли документ или вид в режиме редактирования макроэлемента

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](ksgetobject2dnotifyresult.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](ksgetcurveperpendicularbyt.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [IKompasDocument2D1::EditMacroVisibleRegime](ikompasdocument2d1_editmacrovisibleregime.html).

Синтаксис:

int ksGetEditMacroVisibleRegime( reference p )

Входные параметры:

p | \- указатель на 2D-документ или вид, 0 - текущий документ.  
---|---  
  
Возвращаемое значение:

1 | \- включен визуальный режим редактирования макроэлемента,  
---|---  
0 | \- обычный режим создания/редактирования объектов.  
  
Подразделы:

(отсутствуют)
