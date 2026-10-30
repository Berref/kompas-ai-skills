# AddAdditionCheckButton - Добавить дополнительную кнопку (checkbox)

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl1 ](ipropertycontrol1.html) > [IPropertyControl1 - методы ](ipropertycontrol1_metods.html) |  Scroll [ [ [ ](ipropertycontrol1_gethwnd.html "К следующему разделу")](ipropertycontrol1_metods.html "На уровень выше")](ipropertycontrol1_addadditionbutton.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertycontrol1.html)

Синтаксис Automation:

BOOL AddAdditionCheckButton( long BtnID, VARIANT BmpChecked, VARIANT BmpUnChecked, VARIANT BmpUndefine, BSTR Tips, BSTR IconFont );

Синтаксис COM:

HRESULT AddAdditionCheckButton( long BtnID, VARIANT BmpChecked, VARIANT BmpUnChecked, VARIANT BmpUndefine, BSTR Tips, BSTR IconFont, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

BtnID | \- идентификатор кнопки,  
---|---  
BmpChecked | \- идентификатор иконки из шрифта или идентификатор картинки из ресурсов для нажатого состояния,  
BmpUnChecked | \- идентификатор иконки из шрифта или идентификатор картинки из ресурсов для отжатого состояния  
BmpUndefine | \- идентификатор иконки из шрифта или идентификатор картинки из ресурсов для неопределенного состояния,  
Tips | \- подсказка для кнопки,  
IconFont | \- имя шрифта.  
  
Подразделы:

(отсутствуют)
