/**
* @file text.h
*
* @brief The Text header file.
*/

#ifndef TEXT_H
#define TEXT_H

#include <FrameworkMvdM/entity.h>

/// @brief The Text class
class Text : public Entity
{
public:
	Text(); ///< @brief Constructor of an Text
	virtual ~Text(); ///< @brief Destructor of an Text

	/// @brief update this Text. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime) { };

	/// @brief set the message
	/// @param m the message you want to set
	/// @return void
	void message(std::string m);

	/// @brief clear the message
	/// @return void
	void clearmessage();

private:
	std::string _message;
};


#endif /* TEXT_H */
