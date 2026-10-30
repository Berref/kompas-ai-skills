# AddAdditionButton - Добавить дополнительную кнопку

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl1 ](ipropertycontrol1.html) > [IPropertyControl1 - методы ](ipropertycontrol1_metods.html) |  Scroll [ [ [ ](ipropertycontrol1_addadditioncheckbutton.html "К следующему разделу")](ipropertycontrol1_metods.html "На уровень выше")](ipropertycontrol1_metods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertycontrol1.html)

Синтаксис Automation:

BOOL AddAdditionButton( long BtnID, VARIANT Bmp, BSTR Tips, BSTR IconFont );

Синтаксис COM:

HRESULT AddAdditionButton( long BtnID, VARIANT Bmp, BSTR Tips, BSTR IconFont, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

BtnID | \- идентификатор кнопки,  
---|---  
Bmp | \- идентификатор иконки из шрифта или идентификатор картинки из ресурсов,  
Tips | \- текст подсказки для кнопки,  
IconFont | \- имя библиотечного шрифта.  
  
Подразделы:

(отсутствуют)
