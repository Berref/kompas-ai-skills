////////////////////////////////////////////////////////////////////////////////
//
// 
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventCom.h"

#include "baseEvent.h"
#include "DlgConfig.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CStep1App

BEGIN_MESSAGE_MAP(CEventComApp, CWinApp)
	//{{AFX_MSG_MAP(CStep1App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// The one and only CStep1App object
CEventComApp theApp;

extern BaseEvent* NewApplicationEvent();
extern BaseEvent* NewDocumentEvent( reference doc );
extern BaseEvent* NewDocument2DEvent( reference doc );
extern BaseEvent* NewDocument3DEvent( reference doc );
extern BaseEvent* NewObj2DEvent( reference doc, int objType );
extern BaseEvent* NewObj3DEvent( reference doc, int objType, LPUNKNOWN iObj = NULL );
extern BaseEvent* NewSelectMngEvent( reference doc );
extern BaseEvent* NewSpcDocEvent( reference doc );
extern BaseEvent* NewSpcObjectEvent( reference doc, int objType );
extern BaseEvent* NewSpecificationEvent( reference doc );
extern BaseEvent* NewStampEvent( reference doc );

//-------------------------------------------------------------------------------
// 
// ---
CEventComApp::CEventComApp() : 
  m_iniFile( _T("c:\\EventsCom.ini")),
	m_auto(false),
	m_mes_2DDOC(true),
	m_mes_3DDOC(true),
	m_mes_APP(true),
	m_mes_DOC(true),
	m_mes_OBJ_2DDOC(true),
	m_mes_OBJ_3DDOC(true),
	m_mes_OBJ_SPC(true),
	m_mes_SELECT(true),
	m_mes_SPC(true),
	m_mes_SPCDOC(true),
	m_mes_STAMP(true)
{          
}


//-------------------------------------------------------------------------------
// 
// ---
BOOL CEventComApp::InitInstance() 
{
  TCHAR fileName[256];
  ::_tcscpy_s( fileName, _T("c:\\EventsCom.ini") );
  if( ::GetModuleFileName(theApp.m_hInstance, fileName, 256) ) 
  {
    TCHAR * buf = ::_tcsrchr( fileName, _T('\\'));
    if ( buf )
    {
      *(buf + 1) = _T('\0');
      ::_tcscat_s( fileName, _T("EventsCom.ini") );
    }
  }
//	MessageT( fileName );
  m_iniFile.SetPath( fileName ); 
  m_iniFile.ReadFile();
	m_auto          = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Автоподписка при загрузке                            "), false );
	m_mes_2DDOC     = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий 2D документа          "), true  );
	m_mes_3DDOC     = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий 3D документа          "), true  );
	m_mes_APP       = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий Компаса               "), true  );
	m_mes_DOC       = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий документов            "), true  );
	m_mes_OBJ_2DDOC = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий объекта 2D документа  "), true  );
	m_mes_OBJ_3DDOC = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий объекта 3D документа  "), true  );
	m_mes_OBJ_SPC   = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий объекта спецификации  "), true  );
	m_mes_SELECT    = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий селектирования        "), true  );
	m_mes_SPC       = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий спецификации          "), true  );
	m_mes_SPCDOC    = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий документа спецификации"), true  );
	m_mes_STAMP     = m_iniFile.GetValueB( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий штампа                "), true  );
//	if ( m_auto )
//		MessageT( "True");
//	else
//    MessageT( "False");
	return CWinApp::InitInstance();
}


//-------------------------------------------------------------------------------
// 
// ---
int CEventComApp::ExitInstance() 
{

  m_iniFile.Reset();
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Автоподписка при загрузке                            "), m_auto          );
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий 2D документа          "), m_mes_2DDOC     );
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий 3D документа          "), m_mes_3DDOC     );
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий Компаса               "), m_mes_APP       );
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий документов            "), m_mes_DOC       );
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий объекта 2D документа  "), m_mes_OBJ_2DDOC );
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий объекта 3D документа  "), m_mes_OBJ_3DDOC );
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий объекта спецификации  "), m_mes_OBJ_SPC   );
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий селектирования        "), m_mes_SELECT    );
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий спецификации          "), m_mes_SPC       );
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий документа спецификации"), m_mes_SPCDOC    );
	m_iniFile.SetValueI( _T("Настройки EventCOM"), _T("Выдавать сообщения для событий штампа                "), m_mes_STAMP     );

  m_iniFile.WriteFile();
//  MessageT( "Пишем Cfg" );
  BaseEvent::TerminateEvents();

  delete & BaseEvent::m_EventList;
	return CWinApp::ExitInstance();
}


//-------------------------------------------------------------------------------
// 
// ---
void CEventComApp::ConfigDlg()
{
  DlgConfig dlg;
  
  dlg.m_auto          = m_auto;                      
  dlg.m_mes_2DDOC     = m_mes_2DDOC;    
  dlg.m_mes_3DDOC     = m_mes_3DDOC;    
  dlg.m_mes_APP       = m_mes_APP;      
  dlg.m_mes_DOC       = m_mes_DOC;      
  dlg.m_mes_OBJ_2DDOC = m_mes_OBJ_2DDOC;
  dlg.m_mes_OBJ_3DDOC = m_mes_OBJ_3DDOC;
  dlg.m_mes_OBJ_SPC   = m_mes_OBJ_SPC;  
  dlg.m_mes_SELECT    = m_mes_SELECT;   
  dlg.m_mes_SPC       = m_mes_SPC;      
  dlg.m_mes_SPCDOC    = m_mes_SPCDOC;   
  dlg.m_mes_STAMP     = m_mes_STAMP;    


  dlg.DoModal();

  m_auto          = !!dlg.m_auto;         
  m_mes_2DDOC     = !!dlg.m_mes_2DDOC;    
  m_mes_3DDOC     = !!dlg.m_mes_3DDOC;    
  m_mes_APP       = !!dlg.m_mes_APP;      
  m_mes_DOC       = !!dlg.m_mes_DOC;      
  m_mes_OBJ_2DDOC = !!dlg.m_mes_OBJ_2DDOC;
  m_mes_OBJ_3DDOC = !!dlg.m_mes_OBJ_3DDOC;
  m_mes_OBJ_SPC   = !!dlg.m_mes_OBJ_SPC;  
  m_mes_SELECT    = !!dlg.m_mes_SELECT;   
  m_mes_SPC       = !!dlg.m_mes_SPC;      
  m_mes_SPCDOC    = !!dlg.m_mes_SPCDOC;   
  m_mes_STAMP     = !!dlg.m_mes_STAMP;    
	
}

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
	return ID_LIB;
}


//-------------------------------------------------------------------------------
// Выбор 2D объекта для подписки/отписки
// ---
int SelectObj2DType() {
	double x = 0, y = 0;
  RequestInfoT info;
	memset( &info, 0, sizeof(info) ); 
	info.prompt = _T("Укажите объект");
	int typeObj = 0;
	info.commands = (TCHAR*)IDM_REQUEST_OBJECT;
	int command = CursorExT( &info, &x, &y, 0, NULL );
//	if ( command ) {
 		if ( command < 0 ) {
			reference obj = FindObj( x, y, ::ksGetCursorLimit() );
			if ( obj ) {
	//				if ( YesNoT( _T("По типу объекта?") ) ) 
	//					typeObj = GetObjParam( obj, 0, 0, ALLPARAM_T );
	//				else
					typeObj = obj;
			}
		}
		else {
			if ( command == 1000 )
				ReadIntT( _T("Введите номер типа объекта"), 0, 0/*Все*/, 123/*Вид*/, &command );
			else
				command--;

			typeObj = command; 
		}
//	}
  return typeObj;
}

//-------------------------------------------------------------------------------
// Подписка 2D объекта 
// ---
void AdviseObj2D() {
  reference doc = ::ksGetCurrentDocument( 1 );
	if ( doc ) {
		int typeObj = SelectObj2DType();
		if ( typeObj != -1 ) {
			if ( !BaseEvent::FindEvents( ntObject2DNotify, doc, typeObj ) ) {
				if ( NewObj2DEvent( doc, typeObj ) ) {
					TCHAR buf[255];
					_stprintf_s( buf, _T("Подписались на события для объектов 2D\n typeObj = %i"), typeObj ); 
					MessageT( buf );
				}
				else
					MessageT( _T("Подписаться не удалось") );
			}
			else
 				MessageT( _T("Уже подписались") );
    }
	}
	else
		MessageT( _T("Нет активного 2D документа") );
	
}

//-------------------------------------------------------------------------------
// Отписка 2D объекта 
// ---
void UnAdviseObj2D() {
  reference doc = ::ksGetCurrentDocument( 1 );
	if ( doc ) {
		int typeObj = SelectObj2DType();
		if ( typeObj != -1 ) {
			BaseEvent::TerminateEvents( ntObject2DNotify, doc, typeObj );
			if ( !BaseEvent::FindEvents( ntObject2DNotify, doc, typeObj ) )
				MessageT( _T("Отписались") );
			else
				MessageT( _T("Отписаться не удалось") );
		}
	}
	else
		MessageT( _T("Нет активного 2D документа") );
}


//-------------------------------------------------------------------------------
// Выбор 3D объекта для подписки/отписки
// ---
bool SelectObj3DType( LPUNKNOWN& obj, int& objType ) {
	obj     = NULL;
  objType = o3d_unknown; // 0
	bool res = false;
	reference doc = ::ksGetCurrentDocument( 3 );
	if ( doc ) {
		IDocument3DPtr doc3D( ksGet3dDocumentFromReference(doc), false/*AddRef*/ );
		if ( doc3D ) { 
			IEntityPtr selEnt( doc3D->UserSelectEntity( 0, 0, _bstr_t(_T("Укажите объект")) ), false/*AddRef*/ );
			if ( !ReturnResult() ) {
				if ( selEnt ) {
			  	objType = selEnt->GetType();
					if ( objType == o3d_face || objType == o3d_edge || objType == o3d_vertex ) {
						int resYesNo = YesNoT( _T("Данный тип не поддерживается\n Да - Подписаться на Part\nНет - Подписаться на Feature\nОтмена - не подписываться"));
						switch ( resYesNo ) {
							case 1: 
						    obj = selEnt->GetParent();
					      objType = o3d_part;
							  res = true;
								break;
							case 0: 
								obj = selEnt->GetFeature();
								objType = o3d_feature;
								res = true;
								break;
						}
					}	
					else {
					  obj = selEnt;
			      if( obj )
              obj->AddRef();
            res = true;
					}
				}
			}
      
		}
	}
	return res;
}

//-------------------------------------------------------------------------------
// Выбор объекта спецификации для подписки/отписки
// ---
bool SelectSpcObjType( int& objType, bool byType ) {
  bool res = false;
	reference doc = ::ksGetCurrentDocument( 0 );
  if ( doc ) {
		int type = ksGetDocumentType( doc );
		bool current = false;
		reference spcObj = objType;
		switch ( type ) {
			case lt_DocSpc:
			case lt_DocSpcUser:
			case lt_DocSheetStandart:
			case lt_DocSheetUser: 
			case lt_DocAssemble3D:
			case lt_DocPart3D:
				{
				if ( !byType )
				  spcObj = ksGetCurrentSpcObject();
	    	res = byType || !! (objType = spcObj);
				break;
			}
			default:
				MessageT( _T("Не верный тип документа") );
		}
  }
  return res;
}

//-------------------------------------------------------------------------------
//
// ---
void WINAPI LIBRARYENTRY( unsigned int comm ) {
	// по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
	// из нашей dll вызовем этот define
AFX_MANAGE_STATE(AfxGetStaticModuleState());
  bool byType = false;
  switch ( comm ) { 

		// Подписаться на события приложения Компас
	  case 10 : {      
			if ( !BaseEvent::FindEvents(ntKompasObjectNotify) ) {
      	// обработчик событий приложения КОМПАС
        if ( NewApplicationEvent() )            // подписка на события приложения КОМПАС
					MessageT( _T("Подписались на события приложения КОМПАС"));
				else 
          MessageT( _T("Подписаться не удалось") );
			}		
			else 
        MessageT( _T("Уже подписались") );
				  
			break;
		}
    
		// Отписаться от событий приложения Компас
    case 11 : {  
      if ( BaseEvent::FindEvents(ntKompasObjectNotify) ) {
			  BaseEvent::TerminateEvents( ntKompasObjectNotify );
				MessageT( _T("Отписались") );
      }
			else
				MessageT( _T("Подписка не найдена") );
  		break;
    }
    
		// Подписаться на события документа
		case 20: { 
      reference doc = ::ksGetCurrentDocument( 0 );
      if ( doc ) {
        if ( !BaseEvent::FindEvents( ntDocumentFileNotify, doc ) ) { 
				  if ( NewDocumentEvent( doc ) )
						MessageT( _T("Подписались на события документа") );
					else
						MessageT( _T("Подписаться не удалось") );
				}
				else
  				MessageT( _T("Уже подписались") );
      }
			else
				MessageT( _T("Нет активного документа") );
 			break;
		} 
    
		// Отписаться от событий текущего документа документа 
		case 21: { 
      reference doc = ::ksGetCurrentDocument( 0 );
			if ( doc ) {
				BaseEvent::TerminateEvents( 0, doc );
				if ( !BaseEvent::FindEvents( 0, doc ) ) 
				  MessageT( _T("Отписались от всех событий для текущего документа") );
				else
          MessageT( _T("Отписаться от всех событий для текущего документа не удалось") );
      }
			else
				MessageT( _T("Нет активного документа") );

			break;
		}
			
		// Подписаться на события 2D документа
		case 22: { 
      reference doc = ::ksGetCurrentDocument( 1 );
      if ( doc ) {
        if ( !BaseEvent::FindEvents( ntDocument2DNotify, doc ) ) { 
				  if ( NewDocument2DEvent( doc ) )
						MessageT( _T("Подписались на события 2D документа") );
					else
						MessageT( _T("Подписаться не удалось") );
				}
				else
  				MessageT( _T("Уже подписались") );
      }
			else
				MessageT( _T("Нет активного документа") );
 			break;
		} 
    
		// Отписаться от событий текущего 2D документа 
		case 23: { 
      reference doc = ::ksGetCurrentDocument( 1 );
			if ( doc ) {
				BaseEvent::TerminateEvents( ntDocument2DNotify, doc );
				if ( !BaseEvent::FindEvents( ntDocument2DNotify, doc ) ) 
				  MessageT( _T("Отписались от событий для текущего 2D документа") );
				else
          MessageT( _T("Отписаться от событий для текущего 2D документа не удалось") );
      }
			else
				MessageT( _T("Нет активного документа") );

			break;
		}

    // Подписаться на события редактирования 2D объектов ( указанием объекта ) 
		case 30:	{ 
      AdviseObj2D();
			break;
		}

    // Отписаться от событий редактирования 2D Объектов  
		case 31: { 
			UnAdviseObj2D();
			break;
		}

		// Подписаться на события для вида по номеру	
		case 32: {
			reference doc = ::ksGetCurrentDocument( 1 );
			if ( doc ) {
				int type = ksGetDocumentType(doc);
				if ( type != lt_DocFragment ) {
					int view = 0;
					if ( ReadIntT( _T("Введите номер вида"), 0, 0, 255, &view ) ) {
						reference viewRef = GetViewReference(view);
						if ( viewRef ) {
							if ( !BaseEvent::FindEvents( ntObject2DNotify, doc, viewRef ) ) {
  							if ( NewObj2DEvent( doc, viewRef ) ) 
	  							MessageT( _T("Подписались") );
		  					else
			  					MessageT( _T("Подписаться не удалось") );
							}
							else
      					MessageT( _T("Уже подписались") );
						}
						else 
							MessageT( _T("Вид с таким номером не существует") );
					}
				}
      	else
		   		MessageT( _T("Нет активного чертежа") );
			}
  		else
				MessageT( _T("Нет активного чертежа") );

			break; 
		}

		// Отписаться от событий для вида по номеру	
		case 33: {
			reference doc = ::ksGetCurrentDocument( 1 );
			if ( doc ) {
				int type = ksGetDocumentType(doc);
				if ( type != lt_DocFragment ) {
					int view = 0;
					if ( ReadIntT( _T("Введите номер вида"), 0, 0, 255, &view ) ) {
						reference viewRef = GetViewReference(view);
						if ( viewRef ) {
							BaseEvent::TerminateEvents(ntObject2DNotify, doc, viewRef);
							if ( !BaseEvent::FindEvents( ntObject2DNotify, doc, viewRef ) ) 
								MessageT( _T("Отписались") );
							else
								MessageT( _T("Отписаться не удалось") );
						}
						else 
							MessageT( _T("Вид с таким номером не существует") );
					}
				}
      	else
		   		MessageT( _T("Нет активного чертежа") );
			}
  		else
				MessageT( _T("Нет активного чертежа") );
			break; 
		}

		// Подписаться на события для слоя по номеру	
		case 34: {
			reference doc = ::ksGetCurrentDocument( 1 );
			if ( doc ) {
				int layer = 0;
				if ( ReadIntT( _T("Введите номер слоя"), 0, 0, 254, &layer ) ) {
					reference layerRef = GetLayerReference(layer);
					if ( layerRef ) {
  					if ( !BaseEvent::FindEvents( ntObject2DNotify, doc, layerRef ) ) {
						  if ( NewObj2DEvent( doc, layerRef ) ) 
							  MessageT( _T("Подписались") );
              else
                MessageT( _T("Подписаться не удалось") );
						}
						else
     					MessageT( _T("Уже подписались") );
					}
					else 
						MessageT( _T("Слой с таким номером не существует") );
				}
			}

			break; 
		}

		// Отписаться на слой по номеру	
		case 35: {
			reference doc = ::ksGetCurrentDocument( 1 );
			if ( doc ) {
				int layer = 0;
				if ( ReadIntT( _T("Введите номер слоя"), 0, 0, 254, &layer ) ) {
					reference layerRef = GetLayerReference(layer);
					if ( layerRef ) {
						BaseEvent::TerminateEvents( ntObject2DNotify, doc, layerRef );
						if ( !BaseEvent::FindEvents( ntObject2DNotify, doc, layerRef ) ) 
							MessageT( _T("Отписались") );
						else
							MessageT( _T("Отписаться не удалось") );
					}
					else 
						MessageT( _T("Вид с таким номером не существует") );
				}
			}
  		else
				MessageT( _T("Нет активного документа") );

			break; 
		}

    // Отписать события всех объектов 2D   
		case 36: {
		 	reference doc = ksGetCurrentDocument( 1 );
			if ( doc ) {
			  BaseEvent::TerminateEvents( ntObject2DNotify, doc );
			  MessageT( _T("Отписались") );
			}
  		else
				MessageT( _T("Нет активного 2D документа") );
			break;
		}

		// Подписаться на события селектирования
		case 40: { 
      reference doc = ::ksGetCurrentDocument( 0 );
  		if ( doc ) {
				if ( !BaseEvent::FindEvents( ntSelectionMngNotify, doc ) ) { 
          if ( NewSelectMngEvent( doc  ) )
						MessageT( _T("Подписались") );
					else
						MessageT( _T("Подписаться не удалось") );
				}
  			else
  				MessageT( _T("Уже подписались") );
			}
			else
				MessageT( _T("Нет активного документа") );
			break;
		} 

		// Отписаться от событий селектирования
		case 41: { 
      reference doc = ::ksGetCurrentDocument( 0 );
			if ( doc ) {
				BaseEvent::TerminateEvents( ntSelectionMngNotify, doc );
				if ( !BaseEvent::FindEvents( ntSelectionMngNotify, doc ) )
					MessageT( _T("Отписались") );
        else
				  MessageT( _T("Отписаться не удалось") );
			}
			break;
		}

    // Подписаться на события редактирования штампа  
		case 50:	{ 
      reference doc = ::ksGetCurrentDocument( 0 );
  		if ( doc ) {
        int docType = ::ksGetDocumentType( doc ); 
				switch ( docType ) {
		      case lt_DocSheetStandart :
			    case lt_DocSheetUser     :
          case lt_DocSpc           :
					case lt_DocSpcUser       :
					case lt_DocTxtStandart   :
					case lt_DocTxtUser       : {
						if ( !BaseEvent::FindEvents( ntStampNotify, doc ) ) { 
							if ( NewStampEvent( doc ) )
								MessageT( _T("Подписались") );
							else
								MessageT( _T("Подписаться не удалось") );
						}		
						else
 							MessageT( _T("Уже подписались") );
					  break;
					}
					default:
						MessageT( _T("Неверный тип документа") );
				}
      }
			else
				MessageT( _T("Нет активного документа") );
			break;
		}
			
    // Отписаться от событий редактирования штампа
		case 51: { 
      reference doc = ::ksGetCurrentDocument( 0 );
			if ( doc ) { 
			  BaseEvent::TerminateEvents( ntStampNotify, doc );
			  if ( !BaseEvent::FindEvents( ntStampNotify, doc ) )
				  MessageT( _T("Отписались") );
			  else
				  MessageT( _T("Отписаться не удалось") );
			}
			else
				MessageT( _T("Нет активного документа") );

			break;
		}

    // Подписаться на события 3D документа
		case 60: {
			reference doc = ::ksGetCurrentDocument( 3 );
			if ( doc ) {
				if ( !BaseEvent::FindEvents( ntDocument3DNotify, doc ) ) { 
					if ( NewDocument3DEvent( doc ) )
						MessageT( _T("Подписались") );
					else
						MessageT( _T("Подписаться не удалось") );
				}
        else
					MessageT( _T("Уже подписались") );
      }
  		else
				MessageT( _T("Нет активного 3D документа") );
			break;
		}

    // Отписаться от событий 3D документа
		case 61: {
			reference doc = ::ksGetCurrentDocument( 3 );
			if ( doc ) {
        BaseEvent::TerminateEvents( ntDocument3DNotify, doc );
				if ( !BaseEvent::FindEvents( ntDocument3DNotify, doc ) )  
					MessageT( _T("Отписались") );
				else
					MessageT( _T("Отписаться не удалось") );
      }
  		else
				MessageT( _T("Нет активного 3D документа") );
			break;
		}

		// Подписаться на события редактирования 3D объектов
    case 70: {
			reference doc = ::ksGetCurrentDocument( 3 );
			if ( doc ) {
  			LPUNKNOWN obj = NULL;
        int objType   = o3d_unknown; // 0
				if ( SelectObj3DType( obj, objType ) ) { 
				  if ( NewObj3DEvent( doc, objType, obj ) )
					  MessageT( _T("Подписались") );
					else
					  MessageT( _T("Подписаться не удалось") );
				}
        if ( obj )
          obj->Release();
			}
			else
				MessageT( _T("Нет активного документа 3D") );
			break;
    }
    
		// Отписаться на события редактирования 3D объектов	
    case 80: {
			reference doc = ::ksGetCurrentDocument( 3 );
			if ( doc ) {
  			LPUNKNOWN obj = NULL;
        int objType   = o3d_unknown; // 0
				if ( SelectObj3DType( obj, objType ) ) {
					int typeObj = obj ? 0 : objType;
					BaseEvent::TerminateEvents( ntObject3DNotify, doc, typeObj, obj );
					if ( !BaseEvent::FindEvents( ntObject3DNotify, doc, typeObj, obj ) ) 
            MessageT( _T("Отписались") );
					else
					  MessageT( _T("Отписаться не удалось") );
				}
			}
			else
				MessageT( _T("Нет активного документа 3D") );
			break;
    }


    // Отписать события всех объектов 3D   
		case 90: {
		 	reference doc = ksGetCurrentDocument( 3 );
			if ( doc ) {
			  BaseEvent::TerminateEvents( ntObject3DNotify, doc );
			  MessageT( _T("Отписались") );
			}
  		else
				MessageT( _T("Нет активного 3D документа") );
			break;
		}

		// Подписаться на события редактирования объектов спецификации	
    case 300:
		case 300 + SPC_BASE_OBJECT:
		case 300 + SPC_COMMENT:
      byType = true;
		case 100: {
      int objType = byType ? comm - 300: 0; 
			reference doc = ::ksGetCurrentDocument( 0 );
			if ( doc ) {
	  		if ( SelectSpcObjType( objType, byType ) ) {
		  		if ( !BaseEvent::FindEvents( ntSpcObjectNotify, doc, objType ) ) {
			  	  if ( NewSpcObjectEvent( doc, objType ) ) 
				  		MessageT( _T("Подписались") );
            else
						  MessageT( _T("Подписаться не удалось") );
					}
					else
						MessageT( _T("Уже подписались") );
				}
				else
					MessageT( _T("Нет текущего объекта") );
			}
			else
				MessageT( _T("Нет активного документа") );

			break;
		}
			
		// Отписаться от события редактирования объектов спецификации	
    case 400:
		case 400 + SPC_BASE_OBJECT:
		case 400 + SPC_COMMENT:
      byType = true;
		case 101: { 
      int objType = byType ? comm - 400 : 0; 
			reference doc = ::ksGetCurrentDocument( 0 );
			if ( doc ) {
  			if ( SelectSpcObjType( objType, byType ) ) {
    			BaseEvent::TerminateEvents( ntSpcObjectNotify, doc, objType );
		  		if ( !BaseEvent::FindEvents( ntSpcObjectNotify, doc, objType ) )
					  MessageT( _T("Отписались") );
				  else
			  		MessageT( _T("Отписаться не удалось") );
				}
				else
					MessageT( _T("Нет текущего объекта") ); 
      }
  		else
				MessageT( _T("Нет активного документа") );

      break;
		}


    // Подписаться на события документа спецификации
		case 130: {
			reference doc = ::ksGetCurrentDocument( 2 );
			if ( doc ) {
				if ( !BaseEvent::FindEvents( ntSpcDocumentNotify, doc ) ) { 
					if ( NewSpcDocEvent( doc ) )
						MessageT( _T("Подписались") );
					else
						MessageT( _T("Подписаться не удалось") );
				}
        else
					MessageT( _T("Уже подписались") );
      }
  		else
				MessageT( _T("Нет активного документа спецификации") );
			break;
		}
			

    // Отписаться от событий документа спецификации
		case 131: {
			reference doc = ::ksGetCurrentDocument( 2 );
			if ( doc ) {
        BaseEvent::TerminateEvents( ntSpcDocumentNotify, doc );
				if ( !BaseEvent::FindEvents( ntSpcDocumentNotify, doc ) )  
					MessageT( _T("Отписались") );
				else
					MessageT( _T("Отписаться не удалось") );
      }
  		else
				MessageT( _T("Нет активного документа спецификации") );
			break;
		}

    // Подписаться на события спецификации
		case 140: {
			reference doc = ::ksGetCurrentDocument( 0 );
			if ( doc ) {
				if ( !BaseEvent::FindEvents( ntSpecificationNotify, doc ) ) { 
					if ( NewSpecificationEvent( doc ) )
						MessageT( _T("Подписались") );
					else
						MessageT( _T("Подписаться не удалось") );
				}
        else
					MessageT( _T("Уже подписались") );
      }
  		else
				MessageT( _T("Нет активного документа") );
			break;
		}

    // Отписаться от событий спецификации
		case 141: {
			reference doc = ::ksGetCurrentDocument( 0 );
			if ( doc ) {
        BaseEvent::TerminateEvents( ntSpecificationNotify, doc );
				if ( !BaseEvent::FindEvents( ntSpecificationNotify, doc ) )  
					MessageT( _T("Отписались") );
				else
					MessageT( _T("Отписаться не удалось") );
      }
  		else
				MessageT( _T("Нет активного документа") );
			break;
		}

 
    case 997: // Подписанные события
    {
      BaseEvent::ListEvents();
      break; 
    }

    // Отписать все   
	  case 998: 
	    BaseEvent::TerminateEvents();
			MessageT( _T("Отписались") );
			break;
		
		case 999: // Конфигурация
    { 
      ::theApp.ConfigDlg();
			if ( theApp.m_auto && !BaseEvent::FindEvents( ntKompasObjectNotify ) )
      	NewApplicationEvent();  // обработчик событий приложения КОМПАС
		}
		
		// Подписаться/Отписаться на события 3D объектов по номеру типа   
		default: {
			if ( comm >= ( o3d_unknown + 500 ) && comm <= ( o3d_feature + 500 ) ) {
        // Подписаться
  		 	reference doc = ksGetCurrentDocument( 3 );
	  		if ( doc ) {
		  		int objType = comm - 500;
          if ( !BaseEvent::FindEvents( ntObject3DNotify, doc, objType ) ) {
						if ( NewObj3DEvent( doc, objType ) ) 
							MessageT( _T("Подписались") );
            else
							MessageT( _T("Подписаться не удалось") );
          }
					else
						MessageT( _T("Уже подписались") );
				}
			  else
				  MessageT( _T("Нет активного 3D документа") );
			break;

			}
			else {
  			if ( comm >= ( o3d_unknown + 700 ) && comm <= ( o3d_feature + 700 ) ) {
          // Отписаться
		 			reference doc = ksGetCurrentDocument( 3 );
					if ( doc ) {
						int objType = comm - 700;
						BaseEvent::TerminateEvents( ntObject3DNotify, doc, objType );
						if ( !BaseEvent::FindEvents( ntObject3DNotify, doc, objType ) ) 
							MessageT( _T("Отписались") );
						else
							MessageT( _T("Отписаться не удалось") );
					}
  				else
						MessageT( _T("Нет активного 3D документа") );
					break;
				}
			}
		}
  }
}


//-----------------------------------------------------------------------------
// Провести подписку библиотеки на сообщения системы
// ---
bool WINAPI LibInterfaceNotifyEntry ( LPDISPATCH ){
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
  if ( theApp.m_auto ) {
		if ( !BaseEvent::FindEvents( ntKompasObjectNotify ) )
			NewApplicationEvent();
		reference iter = ::CreateIterator( ALL_DOCUMENTS, 0 );
		if ( iter ) { //создаем итератор для хождения по документам
			reference pDoc = ::MoveIterator( iter, 'F' );
			if ( pDoc ){
				do {
					AdviseDoc( pDoc );
					pDoc = ::MoveIterator(iter, 'N' );
				} while ( pDoc );
			}
  		DeleteIterator( iter );
		}
	}
	return false;
}





//-------------------------------------------------------------------------------
// Подписка на события документа
// ---
void AdviseDoc( long pDoc ) {

	if ( !pDoc )
		pDoc = ::ksGetCurrentDocument( 0 );
	else
    ::SetObjParam(pDoc, NULL, 0, DOCUMENT_STATE);

	if ( pDoc ) {
		int docType = ::ksGetDocumentType( pDoc );
		if ( NewDocumentEvent( pDoc ) ) {
			switch( docType ) {
		  	case lt_DocSheetStandart :
			  case lt_DocSheetUser     :
					NewStampEvent( pDoc ); 
			  case lt_DocFragment      :
					NewDocument2DEvent( pDoc );
				  NewSelectMngEvent( pDoc );
				  NewObj2DEvent( pDoc, ALL_OBJ );
				  break;
			  case lt_DocPart3D :
			  case lt_DocAssemble3D : {
  		    NewDocument3DEvent(pDoc);
				  NewSelectMngEvent( pDoc );
				  NewObj3DEvent( pDoc, o3d_unknown, NULL ); // На все
					break;
				}
				case lt_DocSpc:
				case lt_DocSpcUser: {
					NewSpcDocEvent( pDoc );
					NewStampEvent( pDoc ); 
					break;
				}	
				case lt_DocTxtStandart   :
				case lt_DocTxtUser       : 
					NewStampEvent( pDoc );
					break;
      }    

			switch ( docType ) {
		    case lt_DocSheetStandart:
				case lt_DocSheetUser:
				case lt_DocSpc:
        case lt_DocSpcUser:
				case lt_DocAssemble3D: {
          NewSpecificationEvent( pDoc );
					NewSpcObjectEvent( pDoc, SPC_BASE_OBJECT /*На базовые объекты*/ );
				}
			}
		}
	}
}
