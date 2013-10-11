/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./memory.h"

#include <algorithm>

namespace acs {

Memory::Memory(Random& random, int image_size) : random_(random) {
	Init(image_size);
}

float Memory::GetA(int image_size) const {
	if (image_size > 512)
		return 10.0f;
	if (image_size > 256)
		return 20.0f;
	if (image_size > 128)
		return 30.0f;
	return 40.0f;
}

void Memory::push(cv::Point2i point) {
	memory_.push_back(point);
	if (memory_.size() > 0)
		memory_.pop_front();
}

bool Memory::contains(cv::Point2i point) {
	return std::find(memory_.begin(), memory_.end(), point) != memory_.end();
}

/*
 * Paper says the memory length should be chosen randomly, according to
 * an interval defined by the "A" function.
 */
void Memory::Init(int image_size) {
	float A = GetA(image_size);
	float size = A * (0.85f + random_.next() * 0.30f);

	memory_capacity_ = static_cast<int>(std::floor(size));
}

}  // namespace acs
