# CheckState - Состояние опции

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertySpinEdit ](ipropertyspinedit.html) > [IPropertySpinEdit - свойства ](ipropertyspinedit_props.html) |  Scroll [ [ [ ](ipropertyspinedit_maxvalue.html "К следующему разделу")](ipropertyspinedit_props.html "На уровень выше")](ipropertyspinedit_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyspinedit.html)

Тип данных: состояние опции из перечисления [CheckStateEnum](checkstateenum.html).

Синтаксис Automation:

CheckState = iObject.CheckState | Получить свойство ([* ](1.html))  
---|---  
iObject.CheckState = CheckState | Установить свойство ([* ](1.html))  
CheckState = iObject.GetCheckState() | Получить свойство([**](2.html))  
iObject.SetCheckState (CheckState) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CheckState (&CheckState) | Получить свойство  
---|---  
iObject->put_CheckState (CheckState) | Установить свойство  
  
Примечание:

Это свойство влияет на состояние переключателя, если свойство [WithCheck](ipropertylist_withcheck.html) имеет значение TRUE, и на отображение текста в поле элемента управления, подробнее см. [CheckStateEnum](checkstateenum.html).

Подразделы:

(отсутствуют)
