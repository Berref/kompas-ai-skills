# Add - Создать новый элемент и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroups ](idrawinggroups.html) > [IDrawingGroups - методы ](idrawinggroups_methods.html) |  Scroll [ [ [ ](bb2345331.html "К следующему разделу")](idrawinggroups_methods.html "На уровень выше")](idrawinggroups_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroups.html)

Синтаксис Automation:

LPDISPATCH Add( BOOL temp,

BSTR Name );

Синтаксис COM:

HRESULT Add( BOOL temp,

BSTR Name,

IDrawingGroup ** Result);

Входные параметры:

temp | \- является ли группа временной,  
---|---  
Name | \- имя группы.  
  
Возвращаемое значение:

| \- Указатель на интерфейс группы [IDrawingGroup](idrawinggroup.html).  
---|---  
  
Подразделы:

(отсутствуют)
