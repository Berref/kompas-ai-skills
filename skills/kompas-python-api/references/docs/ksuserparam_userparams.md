# userParams - Безопасный массив SAFEARRAY байтов пользовательских параметров объекта

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Параметры, определяемые пользователем(Интерфейс ksUserParam) ](ksuserparam.html) > [ksUserParam - свойства ](ksuserparam_props.html) |  Scroll [ [ [ ](ksuserparam_methods.html "К следующему разделу")](ksuserparam_props.html "На уровень выше")](ksuserparam_number.html "К предыдущему разделу")  
---|---  
  
[Интерфейс…](ksuserparam.html)

Тип данных: VARIANT

Синтаксис Automation:

userParams = iUserParam.UserParams | Получить свойство ([* ](1.html))  
---|---  
iUserParam.UserParams = userParams | Установить свойство ([* ](1.html))  
userParams = iUserParam.GetUserParams() | Получить свойство ([**](2.html))  
iUserParam.SetUserParams | Установить свойство ([**](2.html))  
  
Значение свойства:

Принимает\возвращает безопасный массив SAFEARRAY типа VT_ARRAY | VT_UI1. |   
---|---  
  
Примечание:

Свойство используется для сохранения/получения пользовательских параметров макроэлемента в виде безопасного массива SAFEARRAY байтов.

Смотрите также

[ksUserParam::GetUserArray](ksuserparam_getuserarray.html)

[ksUserParam::SetUserArray](ksuserparam_setuserarray.html)

Подразделы:

(отсутствуют)
