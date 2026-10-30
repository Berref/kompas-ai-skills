# ksUndoContainer - Включить/отключить объединение операций для Undo

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](kswritegrouptoclip.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](kstrimnurbs.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksUndoContainer](ksdocument2d_ksundocontainer.html).

Синтаксис:

void ksUndoContainer( unsigned char add );

Входные параметры:

add | \- false - закрывает текущий контейнер Undo для объединения операций, true - создает текущий контейнер Undo для объединения операций.  
---|---  
  
Примечание:

Функция позволяет включить/отключить объединение операций для Undo.

Подразделы:

(отсутствуют)
