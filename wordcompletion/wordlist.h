/***************************************************************************
                          wordlist.h  -  description
                             -------------------
    begin                : Don Sep 12 2002
    copyright            : (C) 2002 by Gunnar Schmi Dt
    email                : kmouth@schmi-dt.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

// $Id$

#ifndef WORDLIST_H
#define WORDLIST_H

#include <qxml.h>
#include <qvaluestack.h>
#include <qstring.h>
#include <qmap.h>

namespace WordList {

typedef QMap<QString,int> WordMap;

WordMap createWordList (QString language, QString dictionary);

/**
 * This class implements a parser for reading docbooks and generating word
 * lists. It is intended to be used together with the Qt SAX2 framework.
 * @author Gunnar Schmi Dt
 */

class XMLParser : public QXmlDefaultHandler {
public: 
   XMLParser();
   ~XMLParser();

   bool warning (const QXmlParseException &exception);
   bool error (const QXmlParseException &exception);
   bool fatalError (const QXmlParseException &exception);
   QString errorString();
 
   /** Processes the start of the document. */
   bool startDocument();
                       
   /** Processes the start tag of an element. */
   bool startElement (const QString &, const QString &, const QString &name,
                      const QXmlAttributes &attributes);

   /** Processes a chunk of normal character data. */
   bool characters (const QString &ch);

   /** Processes whitespace. */
   bool ignorableWhitespace (const QString &ch);

   /** Processes the end tag of an element. */
   bool endElement (const QString &, const QString &, const QString &name);
   
   /** Processes the end of the document. */
   bool endDocument();

   /** returns a list of words */
   QStringList getList();

private:
   QStringList list;
   QString text;
};

}

#endif