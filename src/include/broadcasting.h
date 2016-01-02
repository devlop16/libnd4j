/*
 * broadcasting.h
 *
 *  Created on: Dec 28, 2015
 *      Author: agibsonccc
 */

#ifndef BROADCASTING_H_
#define BROADCASTING_H_
#include <stdio.h>
#include <sharedmem.h>
#include <shape.h>
#include <op.h>
#include <templatemath.h>


namespace functions {
	namespace broadcast {

		template<typename T>
		class Broadcast : public functions::ops::Op<T> {
		public:

			/**
             *
             * @param d1
             * @param d2
             * @return
             */
			virtual

#ifdef __CUDACC__
			__device__
#endif
			T op(T d1,T d2) = 0;
			/**
             *
             * @param d1
             * @return
             */
			virtual
#ifdef __CUDACC__
			__device__
#endif T op(T d1) = 0;

#ifdef __CUDACC__
			__device__ void transform(
			T *x, int *xShapeInfo, T *y, int *yShapeInfo, T *result, int *resultShapeInfo,
			int *dimension,
			int dimensionLength,
			int *gpuInformation) {


		int xElementWiseStride = shape::elementWiseStride(xShapeInfo);
		int xOffset = shape::offset(xShapeInfo);
		int yElementWiseStride = shape::elementWiseStride(yShapeInfo);
		int yOffset = shape::offset(yShapeInfo);



		//length for the tad
		int yLength = shape::length(yShapeInfo);
		//length for the tad
		int xLength = shape::length(xShapeInfo);

		int resultLength = shape::length(resultShapeInfo);
		for (int i = blockIdx.x * blockDim.x + threadIdx.x;
				i < resultLength;
				i += blockDim.x * gridDim.x) {
			int yOffset2 = yOffset + ((i / xElementWiseStride) % yLength) * yElementWiseStride;
			if (i < resultLength)
				result[i] = op(x[i], y[yOffset2]);

		}

	}
#endif


			virtual ~Broadcast() {}

		};

		namespace ops {
			template <typename T>
			class Add : public virtual functions::broadcast::Broadcast<T> {
				virtual
#ifdef __CUDACC__
				__host__
#endif
				std::string name() override {
					return std::string("add");
				}

				/**
                 *
                 * @param d1
                 * @param d2
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1,T d2)  {
					return d1 + d2;
				}
				/**
                 *
                 * @param d1
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1) {
					return d1;
				}

				virtual ~Add() {}
			};

			template <typename T>
			class Copy : public virtual functions::broadcast::Broadcast<T> {
				virtual
#ifdef __CUDACC__
				__host__
#endif

				std::string name() override {
					return std::string("copy");
				}

				/**
                 *
                 * @param d1
                 * @param d2
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1,T d2)  {
					return d2;
				}
				/**
                 *
                 * @param d1
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1) {
					return d2;
				}

				virtual ~Copy() {}
			};


			template <typename T>
			class Divide : public virtual functions::broadcast::Broadcast<T> {
				virtual
#ifdef __CUDACC__
				__host__
#endif
				std::string name() override {
					return std::string("div");
				}

				/**
                 *
                 * @param d1
                 * @param d2
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1,T d2)  {
					return d1 / d2;
				}
				/**
                 *
                 * @param d1
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1) {
					return d1;
				}

				virtual ~Divide() {}
			};

			template <typename T>
			class Multiply : public virtual functions::broadcast::Broadcast<T> {
				virtual
#ifdef __CUDACC__
				__host__
#endif
				std::string name() override {
					return std::string("mul");
				}

				/**
                 *
                 * @param d1
                 * @param d2
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1,T d2)  {
					return d1 * d2;
				}
				/**
                 *
                 * @param d1
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1) {
					return d1;
				}

				virtual ~Multiply() {}
			};


			template <typename T>
			class ReverseDivide : public virtual functions::broadcast::Broadcast<T> {
				virtual
#ifdef __CUDACC__
				__host__
#endif
				std::string name() override {
					return std::string("rdiv");
				}

				/**
                 *
                 * @param d1
                 * @param d2
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1,T d2)  {
					return d2 / d1;
				}
				/**
                 *
                 * @param d1
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1) {
					return d1;
				}

				virtual ~ReverseDivide() {}
			};


			template <typename T>
			class ReverseSubtract : public virtual functions::broadcast::Broadcast<T> {
				virtual
#ifdef __CUDACC__
				__host__
#endif
				std::string name() override {
					return std::string("rsub");
				}

				/**
                 *
                 * @param d1
                 * @param d2
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1,T d2)  {
					return d2 - d1;
				}
				/**
                 *
                 * @param d1
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1) {
					return d1;
				}

				virtual ~ReverseSubtract() {}
			};


			template <typename T>
			class Subtract : public virtual functions::broadcast::Broadcast<T> {
				virtual
#ifdef __CUDACC__
				__host__
#endif

				std::string name() override {
					return std::string("sub");
				}

				/**
                 *
                 * @param d1
                 * @param d2
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1,T d2)  {
					return d1 - d2;
				}
				/**
                 *
                 * @param d1
                 * @return
                 */
				virtual
#ifdef __CUDACC__
				__host__ __device__
#endif
				T op(T d1) {
					return d1;
				}

				virtual ~Subtract() {}
			};
		}


	}
}

template<typename T>
inline functions::broadcast::Broadcast<T>::~Broadcast() {
}

#endif /* BROADCASTING_H_ */