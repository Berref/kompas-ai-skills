# AdditionButtonNeedMouseEnterLeaveMessages - Необходимость получать сообщения о наведении/уходе курсора мыши на дополнительных кнопках от данного контрола

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl1 ](ipropertycontrol1.html) > [IPropertyControl1 - свойства ](ipropertycontrol1_props.html) |  Scroll [ [ [ ](ipropertycontrol1_additionbuttonchecked.html "К следующему разделу")](ipropertycontrol1_props.html "На уровень выше")](ipropertycontrol1_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertycontrol1.html)

Тип данных: BOOL

Синтаксис Automation:

AdditionButtonNeedMouseEnterLeaveMessages = Object.AdditionButtonNeedMouseEnterLeaveMessages | Получить свойство([* ](1.html))  
---|---  
Object.AdditionButtonNeedMouseEnterLeaveMessages = AdditionButtonNeedMouseEnterLeaveMessages | Установить свойство ([* ](1.html))  
AdditionButtonNeedMouseEnterLeaveMessages = Object.GetAdditionButtonNeedMouseEnterLeaveMessages() | Получить свойство ([**](2.html))  
Object.SetAdditionButtonNeedMouseEnterLeaveMessages( AdditionButtonNeedMouseEnterLeaveMessages ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AdditionButtonNeedMouseEnterLeaveMessages( &AdditionButtonNeedMouseEnterLeaveMessages ) | Получить свойство([* ](1.html))  
---|---  
Object.put_AdditionButtonNeedMouseEnterLeaveMessages( AdditionButtonNeedMouseEnterLeaveMessages ) | Установить свойство ([* ](1.html))  
  
Входные параметры:

long BtnID | \- пользовательский идентификатор кнопки.  
---|---  
  
Примечание:

Включение свойства позволит обрабатывать событие [ksProcess2DNotify::GetMouseEnterLeavePoint](ksprocess2dnotify_getmouseenterleavepoint.html).

Это позволит подсвечивать точку в поле 2D документа, положение которой зависит от контрола под курсором.

Подразделы:

(отсутствуют)
