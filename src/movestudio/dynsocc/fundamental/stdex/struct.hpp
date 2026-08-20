#ifndef DYNSOCC_FUNDAMENTAL_STDEX_STRUCT_HPP
#define DYNSOCC_FUNDAMENTAL_STDEX_STRUCT_HPP

namespace dynsocc
{
    template <typename T>
    struct dvqueue
    {
        dvqueue(int container_size)
        {
            p_queue = NULL;
            CONTAINER_SIZE = container_size;

            if (container_size > 1000000)
            {
                throw "Exceed size";
            }

            p_queue = (T*)malloc(sizeof(T)*container_size);

            n_s_queue = 0;
            n_e_queue = 0;
            n_c_queue = 0;
            n_margin = 0;
        }

        int enqueue(T val)
        {   
            if (n_c_queue == CONTAINER_SIZE)
            {
                // throw "Out of size";
                return 1;
            }

            p_queue[n_e_queue-n_margin] = val;
            n_c_queue++;
            n_e_queue++;

            if (n_e_queue % CONTAINER_SIZE == 0)
            {
                n_margin += CONTAINER_SIZE;
            }

            return 0;
        }

        int dequeue(int& res)
        {
            if (n_c_queue==0)
            {
                // throw ""; // Empty queue
                return 1; // 
            }

            res = p_queue[n_s_queue-n_margin];
            n_s_queue++;
            n_c_queue--;

            return 0;
        }

        int clear_queue()
        {
            n_s_queue = 0;
            n_e_queue = 0;
            n_c_queue = 0; // Count
            n_margin = 0;
            return 0;
        }

        bool empty()
        {
            return n_c_queue <= 0;
        }

        ~dvqueue()
        {
            if (p_queue != NULL)
            {
                free(p_queue);
                p_queue=NULL;
            }
        }
    private:
        T* p_queue;
        int CONTAINER_SIZE;
        int n_s_queue; // = 0;
        int n_e_queue; // = 0;
        int n_c_queue; // = 0; // Count
        int n_margin; // = 0;
    };


    class test_dvqueue
    {
		public: 
			static int test();
	};

	struct BtreeMap
	{
	public:

	private:
		std::string _vkey[1000];
		std::string _vval[1000];
	};
}

#endif 