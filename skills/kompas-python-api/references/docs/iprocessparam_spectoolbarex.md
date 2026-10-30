# SpecToolbarEx - Специальная панель

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProcessParam ](iprocessparam.html) > [IProcessParam - свойства ](iprocessparam_props.html) |  Scroll [ [ [ ](iprocessparam_methods.html "К следующему разделу")](iprocessparam_props.html "На уровень выше")](iprocessparam_spectoolbar.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocessparam.html)

Тип данных long.

Синтаксис Automation:

SpecToolbarEx = iObject.SpecToolbarEx | Получить свойство ([* ](1.html))  
---|---  
iObject.SpecToolbarEx = SpecToolbarEx | Установить свойство ([* ](1.html))  
SpecToolbarEx = iObject.GetSpecToolbarEx() | Получить свойство([**](2.html))  
iObject.SetSpecToolbarEx(SpecToolbarEx) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SpecToolbarEx(&SpecToolbarEx) | Получить свойство  
---|---  
iObject->put_SpecToolbarEx(SpecToolbarEx) | Установить свойство  
  
Значение свойства:

long идентификатор спецпанели в Панели свойств.

Примечание:

Данное свойство является расширением свойства [SpecToolbar](iprocessparam_spectoolbar.html).

Свойство позволяет установить или получить идентификатор спецпанели. Может быть установлен идентификатор из перечисления [SpecPropertyToolBarEnum](specpropertytoolbarenum.html) \- Предопределенные спецпанели для панели свойств либо задан идентификатор ресурса пользовательской спецпанели, уникальный в рамках библиотеки.

Свойство SpecToolbarEx используется совместно со свойствами [ResModule](iprocessparam_resmodule.html) и [BmpBeginId](iprocessparam_bmpbeginid.html).

Чтобы описать пользовательскую спецпанель, нужно:

1\. Объявить уникальный идентификатор спецпанели в h файле

#define ITB_SPEC_TOOLBAR 3000

#define END_OF_RESOURCE_TABLE 0xffff

2\. В ресурсном файле описать RCDATA панели и пользовательские кнопки

rc2-файл:

ITB_SPEC_TOOLBAR RCDATA

{

1 //pbEnter

2 //pbEsc

3 //pbHelpсправка

20 //пользовательская кнопка

END_OF_RESOURCE_TABLE

}

В примере для пользовательской спецпанели определено 4 кнопки.

1, 2, 3 - предопределенные кнопки из перечисления [SpecPropertyToolBarEnum](specpropertytoolbarenum.html)

20 - пользовательская кнопка

//битмап для пользовательской кнопки спецпанели

20 BITMAP "res\\\st_reduc.bmp" // CREATE процесса настройки фильтра для выбора объектов отчета

//tips\hint для пользовательской кнопки спецпанели

STRINGTABLE LOADONCALL MOVEABLE DISCARDABLE

BEGIN

20 "Для тестирования пользовательской кнопки\nПользовательская кнопка"

END

Подразделы:

(отсутствуют)
