# sheetType - Тип листа

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров формата и компоновки чертежа ](ce1717197.html) > [Оформление (Интерфейс ksSheetOptions) ](kssheetoptions.html) > [ksSheetOptions - свойства ](kssheetoptions_props.html) |  Scroll [ [ [ ](kssheetoptions_shttype.html "К следующему разделу")](kssheetoptions_props.html "На уровень выше")](kssheetoptions_layoutname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssheetoptions.html)

Тип данных:BOOL.

Синтаксис Automation:

sheetType = iSheetOptions.sheetType | Получить свойство ([* ](1.html))  
---|---  
iSheetOptions.sheetType = sheetType | Установить свойство ([* ](1.html))  
sheetType = iSheetOptions.GetSheetType() | Получить свойство ([**](2.html))  
iSheetOptions.SetSheetType (sheetType) | Установить свойство ([**](2.html))  
  
Значения свойства:

TRUE | \- пользовательский формат,  
---|---  
FALSE | \- стандартный лист.  
  
Примечание:

Свойство необходимо учитывать при вызове метода [GetSheetParam](kssheetoptions_getsheetparam.html). Значение свойства должно соответствовать значению входного параметра type. Осталась для совместимости со старыми библиотеками.

Подразделы:

(отсутствуют)
