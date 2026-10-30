# ksReadGroupFromClip - Прочитать графические объекты из буфера обмена и разместить их во временной группе

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](kssetorthomode.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](kssetcursortextw.html "К предыдущему разделу")  
---|---  
  
[Пример...](kswritereadgroup_clip_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksReadGroupFromClip](ksdocument2d_ksreadgroupfromclip.html).

Синтаксис:

reference ksReadGroupFromClip();

Возвращаемое значение:

указатель на группу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Графические объекты должны принадлежать одному виду.

2\. Параметрические связи и ограничения объектов при чтении из буфера теряются, атрибуты сохраняются.

Подразделы:

(отсутствуют)
