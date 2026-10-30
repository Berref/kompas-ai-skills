# CurrentCursorStep - Текущий шаг дискретного перемещения курсора

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - свойства ](idocumentframe_props.html) |  Scroll [ [ [ ](idocumentframe_regime.html "К следующему разделу")](idocumentframe_props.html "На уровень выше")](idocumentframe_caption.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Тип данных: BOOL

Синтаксис Automation:

CurrentCursorStep = Object.CurrentCursorStep( ) | Получить свойство ([* ](1.html))  
---|---  
CurrentCursorStep = Object.GetCurrentCursorStep() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_CurrentCursorStep( &CurrentCursorStep ) | Получить свойство  
---|---  
  
Примечание

При включенном режиме округления [IDocumentFrame::RoundModeOn](idocumentframe_roundmodeon.html) значения параметров округляются до ближайшего значения, кратного текущему шагу курсора.

Подразделы:

(отсутствуют)
