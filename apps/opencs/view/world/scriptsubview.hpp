#ifndef CSV_WORLD_SCRIPTSUBVIEW_H
#define CSV_WORLD_SCRIPTSUBVIEW_H

#include "../doc/subview.hpp"

class QTextEdit;
class QModelIndex;

namespace CSMDoc
{
    class Document;
}

namespace CSMWorld
{
    class IdTable;
}

namespace CSVWorld
{
    class ScriptSubView : public CSVDoc::SubView
    {
            Q_OBJECT

            QTextEdit *mEditor;
            CSMDoc::Document& mDocument;
            CSMWorld::IdTable *mModel;
            int mColumn;
            int mChangeLocked;

            class ChangeLock
            {
                    ScriptSubView& mView;

                    ChangeLock (const ChangeLock&);
                    ChangeLock& operator= (const ChangeLock&);

                public:

                    ChangeLock (ScriptSubView& view);
                    ~ChangeLock();
            };

            friend class ChangeLock;

        public:

            ScriptSubView (const CSMWorld::UniversalId& id, CSMDoc::Document& document);

            virtual void setEditLock (bool locked);

        private slots:

            void textChanged();

            void dataChanged (const QModelIndex& topLeft, const QModelIndex& bottomRight);

            void rowsAboutToBeRemoved (const QModelIndex& parent, int start, int end);
    };
}

#endif