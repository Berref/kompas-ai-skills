# NeedMouseEnterLeaveMessages - Необходимость получать сообщения о наведении/уходе курсора мыши на поле редактирования контрола

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl1 ](ipropertycontrol1.html) > [IPropertyControl1 - свойства ](ipropertycontrol1_props.html) |  Scroll [ [ [ ](ipropertycontrol1_predefinenumber.html "К следующему разделу")](ipropertycontrol1_props.html "На уровень выше")](ipropertycontrol1_image.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertycontrol1.html)

Тип данных: BOOL

Синтаксис Automation:

NeedMouseEnterLeaveMessages = Object.NeedMouseEnterLeaveMessages | Получить свойство([* ](1.html))  
---|---  
Object.NeedMouseEnterLeaveMessages = NeedMouseEnterLeaveMessages | Установить свойство ([* ](1.html))  
NeedMouseEnterLeaveMessages = Object.GetNeedMouseEnterLeaveMessages() | Получить свойство ([**](2.html))  
Object.SetNeedMouseEnterLeaveMessages( NeedMouseEnterLeaveMessages ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_NeedMouseEnterLeaveMessages( &NeedMouseEnterLeaveMessages ) | Получить свойство([* ](1.html))  
---|---  
Object.put_NeedMouseEnterLeaveMessages( NeedMouseEnterLeaveMessages ) | Установить свойство ([* ](1.html))  
  
Примечание:

Включение свойства позволит обрабатывать событие [ksProcess2DNotify::GetMouseEnterLeavePoint](ksprocess2dnotify_getmouseenterleavepoint.html).

Это позволит подсвечивать точку в поле 2D документа, положение которой зависит от контрола под курсором.

Подразделы:

(отсутствуют)
