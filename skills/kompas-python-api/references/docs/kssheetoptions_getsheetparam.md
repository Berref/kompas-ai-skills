# GetSheetParam - Получить указатель на интерфейс параметров листа документа

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров формата и компоновки чертежа ](ce1717197.html) > [Оформление (Интерфейс ksSheetOptions) ](kssheetoptions.html) > [ksSheetOptions - методы ](kssheetoptions_methods.html) |  Scroll [ [ [ ](kssheetoptions_init.html "К следующему разделу")](kssheetoptions_methods.html "На уровень выше")](kssheetoptions_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssheetoptions.html)

Синтаксис Automation:

LPDISPATCH GetSheetParam (BOOL type);

Входной параметр:

type | \- признак формата листа: FALSE - стандартный лист, TRUE - пользовательский формат.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс параметров листа [ksStandartSheet](ksstandartsheet.html) или [ksSheetSize](kssheetsize.html).  
---|---  
  
Примечание:

При вызове метода необходимо учитывать свойство [sheetType](kssheetoptions_sheettype.html). Его значение должно соответствовать значению входного параметра type. Осталась для совместимости со старыми библиотеками.

Подразделы:

(отсутствуют)
