# SpecToolbarEx - Пользовательская спецпанель

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyManager ](ipropertymanager.html) > [IPropertyManager - свойства ](ipropertymanager_props.html) |  Scroll [ [ [ ](ipropertymanager_statusmessage.html "К следующему разделу")](ipropertymanager_props.html "На уровень выше")](ipropertymanager_spectoolbar.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymanager.html)

Тип данных: long.

Синтаксис Automation:

SpecToolbarEx = Object.SpecToolbarEx | Получить свойство ([* ](1.html))  
---|---  
Object.SpecToolbarEx = SpecToolbarEx | Установить свойство ([* ](1.html))  
SpecToolbarEx = Object.GetSpecToolbarEx() | Получить свойство([**](2.html))  
Object.SetSpecToolbarEx( SpecToolbarEx ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SpecToolbarEx( &SpecToolbarEx ) | Получить свойство  
---|---  
Object.put_SpecToolbarEx( SpecToolbarEx ) | Установить свойство  
  
Примечание:

1\. Данное свойство является расширением свойства [IPropertyManager::SpecToolbar](ipropertymanager_spectoolbar.html).

2\. Свойство позволяет установить или получить идентификатор спецпанели.

Может быть установлен идентификатор из перечисления [SpecPropertyToolBarEnum](specpropertytoolbarenum.html) (предопределенных спецпанелей для панели свойств) либо задан идентификатор ресурса пользовательской спецпанели, уникальный в рамках библиотеки.

3\. Свойство SpecToolbarEx используется совместно со свойством [IPropertyManager::ResModule](ipropertymanager_resmodule.html).

4\. Чтобы описать пользовательскую спецпанель, нужно:

4.1. Объявить уникальный идентификатор спецпанели в h файле

#define ITB_SPEC_TOOLBAR 3000

#define END_OF_RESOURCE_TABLE 0xffff

4.2. В ресурсном файле описать RCDATA панели и пользовательские кнопки

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

1, 2, 3 - предопределенные кнопки из перечисления SpecPropertyToolBarEnum

20 - пользовательская кнопка

//битмап для пользовательской кнопки спецпанели

20 ICON DISCARDABLE "res\\\st_reduc.ico" // CREATE процесса настройки фильтра для выбора объектов отчета

//tips\hint для пользовательской кнопки спецпанели

STRINGTABLE LOADONCALL MOVEABLE DISCARDABLE

BEGIN

20 "Для тестирования пользовательской кнопки\nПользовательская кнопка"

END

Подразделы:

(отсутствуют)
