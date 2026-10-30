# ksGetSnapInfo - Получить текущую информацию о привязках

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](ksmovepointoncurve.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](ksgetparametrizationparam.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

ISnapInfo * LIB_FUNC ksGetSnapInfo();

Возвращаемое значение:

| \- интерфейс информации о текущей привязке [ISnapInfo](isnapinfo.html).  
---|---  
  
Примечание:

Функция позволяет получить информацию о привязке к объектам документа, сетке документа и о других типах привязки в процессах [CursorEx](cursorex.html), [PlacementEx](placementex.html).

Типы возможных привязок см. в перечислении ksSnapTypeEnum.

Подразделы:

(отсутствуют)
