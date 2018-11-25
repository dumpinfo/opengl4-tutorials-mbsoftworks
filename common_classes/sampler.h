#pragma once

#include <glad/glad.h>

enum MagnificationFilter
{
	MAG_FILTER_NEAREST, // Nearest filter for magnification
	MAG_FILTER_BILINEAR, // Bilinear filter for magnification
};

enum MinificationFilter
{
	MIN_FILTER_NEAREST, // Nearest filter for minification
	MIN_FILTER_BILINEAR, // Bilinear filter for minification
	MIN_FILTER_NEAREST_MIPMAP, // Nearest filter for minification, but on closest mipmap
	MIN_FILTER_BILINEAR_MIPMAP, // Bilinear filter for minification, but on closest mipmap
	MIN_FILTER_TRILINEAR, // Bilinear filter for minification on two closest mipmaps, then averaged
};

class Sampler
{
public:
	/** \brief  Creates sampler object. */
	void create();

	/** \brief  Binds sampler object to specific texture unit.
	*   \param  textureUnit  Texture unit index to bind sampler to
	*/
	void bind(int textureUnit = 0) const;

	/** \brief  Deletes sampler object. */
	void deleteSampler();

	/** \brief  Sets magnification filter of the sampler.
	*   \param  magnificationFilter  Magnification filter
	*/
	void setMagnificationFilter(MagnificationFilter magnificationFilter) const;

	/** \brief  Sets minification filter of the sampler.
	*   \param  minificationFilter  Minification filter
	*/
	void setMinificationFilter(MinificationFilter minificationFilter) const;

	/** \brief  Sets the texture repetition with the sampler.
	*   \param  repeat  True, if the texture should be repeated or false, if it should be clamped
	*/
	void setRepeat(bool repeat) const;

private:
	GLuint _samplerID = 0; //!< OpenGL-assigned sampler ID
	bool _isCreated = false; //!< Flag telling, if sampler has been created

	/** \brief  Checks, if the sampler has been created and if not, logs it into console.
	*   \return True, if sampler has been created or false otherwise.
	*/
	bool createdCheck() const;
};